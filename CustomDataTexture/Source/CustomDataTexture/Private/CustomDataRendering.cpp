#include "CustomDataAPI.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/World.h"
#include "GlobalShader.h"
#include "PipelineStateCache.h"
#include "RHIStaticStates.h"

#include "ShaderParameterUtils.h"
#include "CustomDataBlueprintLibrary.h"
#include "CustomDataBlueprintLibrary.h"
#include "ShaderParameterMacros.h"
#include "ShaderParameterStruct.h"
#include "ShaderParameterUtils.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Rendering/MultiSizeIndexContainer.h"
#include "Rendering/SkeletalMeshRenderData.h"
#include "SkeletalRenderPublic.h"
#include "Containers/Array.h"
#include "RHIResources.h"
#include "RHICommandList.h"
#include "RenderResource.h"
#include "RendererInterface.h"
#include "Runtime/Renderer/Private/PostProcess/SceneRenderTargets.h"
#include "Misc/EnumClassFlags.h"
static FVertexBufferRHIRef CreateVertexBufferWithData(TArray<FVertex>& data) {
    FRHIResourceCreateInfo info;
    auto size = sizeof(FVertex) * data.Num();
    FVertexBufferRHIRef buf = RHICreateVertexBuffer(size, BUF_Static | BUF_ShaderResource, info);
    void* ptr = static_cast<void*>(RHILockVertexBuffer(buf, 0, size, RLM_WriteOnly));
    FMemory::Memcpy(ptr, static_cast<void*>(data.GetData()), size);
    RHIUnlockVertexBuffer(buf);
    return buf;
}

struct FOBJPositionBuffer : public FVertexBuffer {
    TArray<FVertex> Vertices;
	int check;
    FShaderResourceViewRHIRef PositionComponentSRV;
	FVertexDeclarationRHIRef vertexDeclaration;
	void createVertDeclaration() {
		FVertexDeclarationElementList Elements;
		uint32 Stride = sizeof(FVertex);
		check = (int)Stride;
		
		
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, transformComp0), VET_Float4, 0, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, transformComp1), VET_Float4, 1, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, transformComp2), VET_Float4, 2, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, transformComp3), VET_Float4, 3, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, vertex), VET_Float4, 4, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, scale), VET_Float3, 5, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FVertex, color), VET_Float4, 6, Stride));
		vertexDeclaration = RHICreateVertexDeclaration(Elements);
		
	}
    virtual void InitRHI() override {
        FRHIResourceCreateInfo info;
        VertexBufferRHI = CreateVertexBufferWithData(Vertices);
		createVertDeclaration();
    }
};
struct FOBJIndexBuffer : public FIndexBuffer {
    TArray<uint32> Indices;

    virtual void InitRHI() override {
        FRHIResourceCreateInfo info;
        auto ElementSizeInBytes = sizeof(uint32);
        auto ArraySize = ElementSizeInBytes * Indices.Num();
        IndexBufferRHI = RHICreateIndexBuffer(ElementSizeInBytes, ArraySize, BUF_Static, info);
        void* ptr = static_cast<void*>(RHILockIndexBuffer(IndexBufferRHI, 0, ArraySize, RLM_WriteOnly));
        FMemory::Memcpy(ptr, static_cast<void*>(Indices.GetData()), ArraySize);
        RHIUnlockIndexBuffer(IndexBufferRHI);
    }
};
struct FCompiledCDTGModel
{
    /** Orignal camera model that has generated this compiled model. */
    FCustomDataTextureGenerationModel model;

    /** Camera matrices of the lens distortion for the undistorted and distorted render.
     *  XY holds the scales factors, ZW holds the translates.
     */
	TArray<FVertex> vtex;
	TArray<uint32> indices;
    FMatrix ViewMatrix;
    FMatrix ProjMatrix;

};
class FCustomDataGenerationShader : public FGlobalShader
{
public:
    

    
   
};



class FCustomDataGenerationVS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FCustomDataGenerationVS);
    SHADER_USE_PARAMETER_STRUCT(FCustomDataGenerationVS, FGlobalShader)
        BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FMatrix, ProjectionMatrix)
        SHADER_PARAMETER(FMatrix,ViewMatrix)
        END_SHADER_PARAMETER_STRUCT()

public:


    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }

    /** Initialization constructor. */
    //FCustomDataGenerationVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
      //  : FGlobalShader(Initializer)
    //{
    //}
private:
    LAYOUT_FIELD(FShaderResourceParameter, ProjectionMatrix)
    LAYOUT_FIELD(FShaderResourceParameter, ViewMatrix)
};

class FCustomDataGenerationPS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FCustomDataGenerationPS);
    SHADER_USE_PARAMETER_STRUCT(FCustomDataGenerationPS, FGlobalShader)
        BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FMatrix, ProjectionMatrix)
        SHADER_PARAMETER(FMatrix, ViewMatrix)
        END_SHADER_PARAMETER_STRUCT()

public:
  

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
    }

    /** Initialization constructor. */
    //FCustomDataGenerationPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
      //  : FGlobalShader(Initializer)
    //{ }
private:
    LAYOUT_FIELD(FShaderResourceParameter,ProjectionMatrix)
    LAYOUT_FIELD(FShaderResourceParameter, ViewMatrix)
};

IMPLEMENT_SHADER_TYPE(, FCustomDataGenerationVS, TEXT("/CustomDataTexture/Private/customDataTextureShader.usf"), TEXT("MainVS"), SF_Vertex)
IMPLEMENT_SHADER_TYPE(, FCustomDataGenerationPS, TEXT("/CustomDataTexture/Private/customDataTextureShader.usf"), TEXT("MainPS"), SF_Pixel)

static void DrawCustomDataToRenderTarget_RenderThread(
    FRHICommandListImmediate& RHICmdList,
    const FCompiledCDTGModel& CompiledModel,
    const FName& TextureRenderTargetName,
    FTextureRenderTargetResource* OutTextureRenderTargetResource,
    ERHIFeatureLevel::Type FeatureLevel)
{
    check(IsInRenderingThread());

#if WANTS_DRAW_MESH_EVENTS
    FString EventName;
    TextureRenderTargetName.ToString(EventName);
    SCOPED_DRAW_EVENTF(RHICmdList, SceneCapture, TEXT("CustomDataTextureDataGeneration %s"), *EventName);
#else
    SCOPED_DRAW_EVENT(RHICmdList, DrawUVDisplacementToRenderTarget_RenderThread);
#endif

    // Set render target.
    //SetRenderTarget(
      //  RHICmdList,
        //OutTextureRenderTargetResource->GetRenderTargetTexture(),
        //FTextureRHIRef(),
        //ESimpleRenderTargetMode::EUninitializedColorAndDepth,
        //FExclusiveDepthStencil::DepthNop_StencilNop);
	
	const TCHAR* Name = TEXT("Render_DS");
	FRHIResourceCreateInfo DepthStencilTexCreateInfo(Name);
	DepthStencilTexCreateInfo.ClearValueBinding = FClearValueBinding(0.0f, 0);
	FTexture2DRHIRef DepthStencilTex = RHICreateTexture2D(
		OutTextureRenderTargetResource->GetSizeX(), OutTextureRenderTargetResource->GetSizeY(), PF_DepthStencil, 1, 1, TexCreate_DepthStencilTargetable, ERHIAccess::DSVWrite, DepthStencilTexCreateInfo);

	FRHIRenderPassInfo RPInfo(OutTextureRenderTargetResource->GetRenderTargetTexture(), ERenderTargetActions::Clear_Store, DepthStencilTex, MakeDepthStencilTargetActions(ERenderTargetActions::Clear_Store, ERenderTargetActions::Clear_Store), FExclusiveDepthStencil::DepthWrite_StencilWrite);
	//FRHIRenderPassInfo RPInfo(OutTextureRenderTargetResource->GetRenderTargetTexture(), ERenderTargetActions::Load_Store, DepthStencilTex, MakeDepthStencilTargetActions(ERenderTargetActions::Clear_Store, ERenderTargetActions::Clear_DontStore), FExclusiveDepthStencil::DepthNop_StencilWrite);
	//PInfo.DepthStencilRenderTarget.Action = MakeDepthStencilTargetActions(ERenderTargetActions::Clear_Store, ERenderTargetActions::Clear_Store);
	//FTexture2DRHIRef DepthStencilTexRes = RHICmdList.CreateTexture2D(
		//OutTextureRenderTargetResource->GetSizeX(), OutTextureRenderTargetResource->GetSizeY(), PF_DepthStencil, 1, 1, TexCreate_DepthStencilResolveTarget, DepthStencilTexCreateInfo);

	//RPInfo.DepthStencilRenderTarget.DepthStencilTarget = DepthStencilTex;
	//RPInfo.DepthStencilRenderTarget.ResolveTarget = DepthStencilTex;
	//RPInfo.DepthStencilRenderTarget.ExclusiveDepthStencil = FExclusiveDepthStencil::DepthWrite_StencilWrite;
	
	if (CompiledModel.vtex.Num() > 0) {

	RHICmdList.BeginRenderPass(RPInfo, TEXT("DrawCustomData"));
	//RHICmdList.SetStencilRef(0);
	FIntPoint DisplacementMapResolution(OutTextureRenderTargetResource->GetSizeX(), OutTextureRenderTargetResource->GetSizeY());

    // Update viewport.
    //RHICmdList.SetViewport(
      //  0, 0, 0.f,
		//OutTextureRenderTargetResource->GetSizeX(), OutTextureRenderTargetResource->GetSizeY(), 1.f);
	RHICmdList.SetViewport(
		0, 0, 0.f,
		OutTextureRenderTargetResource->GetSizeX(), OutTextureRenderTargetResource->GetSizeY(), 1.f);
    // Get shaders.
    //TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);
    TShaderMapRef< FCustomDataGenerationVS > VertexShader(GetGlobalShaderMap(FeatureLevel));
    TShaderMapRef< FCustomDataGenerationPS > PixelShader(GetGlobalShaderMap(FeatureLevel));
		FOBJPositionBuffer posBuffer;
		FOBJIndexBuffer indexBuffer;
		posBuffer.Vertices = CompiledModel.vtex;
		indexBuffer.Indices = CompiledModel.indices;
		BeginInitResource(&posBuffer);
		BeginInitResource(&indexBuffer);
		// Set the graphic pipeline state.
		
		FGraphicsPipelineStateInitializer GraphicsPSOInit;
		//RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
		//GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<true, CF_DepthNearOrEqual, false, CF_LessEqual, SO_Keep, SO_Keep, SO_Replace,
			//false, CF_LessEqual, SO_Keep, SO_Keep, SO_Replace, 0xFF, 0xFF >::GetRHI();
		 //GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<true, CF_Always, true, CF_LessEqual, SO_Replace, SO_Replace, SO_Keep,
			//true, CF_LessEqual, SO_Replace, SO_Replace, SO_Keep, 0xFF, 0xFF >::GetRHI();
		//GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<true, CF_Always>::GetRHI();
		GraphicsPSOInit.DepthStencilAccess = FExclusiveDepthStencil::DepthWrite_StencilWrite;
		
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<true, CF_DepthNear, true, CF_LessEqual, SO_Replace, SO_Replace, SO_Keep,
			false, CF_LessEqual, SO_Replace, SO_Replace, SO_Replace, 0xFF, 0xFF >::GetRHI();
		//GraphicsPSOInit.DepthStencilState->ActualDSMode = FExclusiveDepthStencil::DepthWrite_StencilWrite;
		
		//GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<true, CF_DepthNear, true, CF_LessEqual, SO_Replace, SO_Replace, SO_Keep,
			//true, CF_LessEqual, SO_Replace, SO_Replace, SO_Keep, 0x01, 0x01 >::GetRHI();
		//GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<true, CF_Always, true, CF_Always, SO_Keep, SO_Replace, SO_Replace,
			//false, CF_Always, SO_Keep, SO_Keep, SO_Keep, 0x02, 0x02 >::GetRHI();
			//GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState < true, CF_DepthNear>::GetRHI();
		GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
		//GraphicsPSOInit.BlendState = TStaticBlendState<CW_NONE>::GetRHI();
		//GraphicsPSOInit.BlendState = TStaticBlendStateWriteMask<CW_RGBA, CW_RGBA, CW_RGBA, CW_RGBA>::GetRHI();
		//GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB, BO_Add, BF_One, BF_One>::GetRHI();
		//GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<FM_Solid, CM_CW>::GetRHI();
		GraphicsPSOInit.PrimitiveType = PT_TriangleList;
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = posBuffer.vertexDeclaration;
		//GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		//GraphicsPSOInit.RenderTargetFormats[0] = 10;
		//GraphicsPSOInit.RenderTargetFlags[0] = 9;
		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit,EApplyRendertargetOption::CheckApply);
		//FGraphicsPipelineStateInitializer GraphicsPSOInitNew = GraphicsPSOInit;
		//RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInitNew);



		// Update viewport.
	
		FCustomDataGenerationVS::FParameters passParameter;
		passParameter.ProjectionMatrix = CompiledModel.ProjMatrix;
		passParameter.ViewMatrix = CompiledModel.ViewMatrix;
		FCustomDataGenerationPS::FParameters passParameterPS;
		passParameter.ProjectionMatrix = CompiledModel.ProjMatrix;
		passParameter.ViewMatrix = CompiledModel.ViewMatrix;
		// Update shader uniform parameters.
		SetShaderParameters(RHICmdList, VertexShader, VertexShader.GetVertexShader(), passParameter);
		SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), passParameterPS);
		RHICmdList.SetStreamSource(0, posBuffer.VertexBufferRHI, 0);
		RHICmdList.DrawIndexedPrimitive(indexBuffer.IndexBufferRHI, 0, 0, CompiledModel.vtex.Num(), 0, CompiledModel.indices.Num() / 3, 0);
		//RHICmdList.DrawIndexedPrimitiveIndirect(indexBuffer.IndexBufferRHI, posBuffer.VertexBufferRHI, 0);



		// Resolve render target.
		RHICmdList.CopyToResolveTarget(
			OutTextureRenderTargetResource->GetRenderTargetTexture(),
			OutTextureRenderTargetResource->TextureRHI,
			FResolveParams());

		indexBuffer.ReleaseResource();
		posBuffer.ReleaseResource();
		RHICmdList.EndRenderPass();
	}
}
void FCustomDataTextureGenerationModel::BuildArrays() {
        int triCount = 0;
		transforms.Empty();
		vertices.Empty();
		scales.Empty();
		triangles.Empty();
		vtex.Empty();

        for (int i = 1; i < Actors.Num(); i++) {

            TInlineComponentArray<UStaticMeshComponent*> StaticComps;
			Actors[i]->GetComponents(StaticComps);
            for (int k = 0; k < StaticComps.Num(); k++) {
					//Populate vertex and indices
					TArray<FVector> verts = GetVerticesFromStaticMesh(StaticComps[k]);
					TArray<uint32> tris = GetTrisFromStaticMesh(StaticComps[k]);
					TArray<FMatrix> trans;
					TArray<FVector> scale;
					for (int j = 0; j < verts.Num(); j++) {
						// A - Populate per Vertex of an mesh
						trans.Add(Actors[i]->GetActorTransform().ToMatrixWithScale());
						scale.Add(Actors[i]->GetActorScale());
					}
					for (int j = 0; j < tris.Num(); j++) {
						tris[j] += triCount;
						triangles.Add(tris[j]);
					}
					for (int j = 0; j < verts.Num(); j++) {
						//B - add to model arrays
						vertices.Add(verts[j]);
						transforms.Add(trans[j]);
						scales.Add(scale[j]);
					}

					triCount = vertices.Num();
				}
            TInlineComponentArray<USkeletalMeshComponent*> Skellies;
            Actors[i]->GetComponents(Skellies);
			for (int k = 0; k < Skellies.Num(); k++) {
				if (Skellies[k]->IsActive()) {
					TArray<FVector> verts = GetVerticesFromSkellieMesh(Skellies[k]);
					TArray<uint32> tris = GetTrisFromSkellieMesh(Skellies[k]);
					TArray<FMatrix> trans;
					TArray<FVector> scale;
					for (int j = 0; j < verts.Num(); j++) {
						trans.Add(Actors[i]->GetActorTransform().ToMatrixWithScale());
						scale.Add(Actors[i]->GetActorScale());
					}
					for (int j = 0; j < tris.Num(); j++) {
						tris[j] += triCount;
						triangles.Add(tris[j]);
					}

					for (int j = 0; j < verts.Num(); j++) {
						vertices.Add(verts[j]);
						transforms.Add(trans[j]);
						scales.Add(scale[j]);
					}
					triCount = vertices.Num();
				}

			}
        }
        for (int i = 0; i < vertices.Num(); i++) {
			TArray<FVector4> matRows;
			for (int k = 0; k < 4; k++) {
				matRows.Add(FVector4(transforms[i].M[k][0], transforms[i].M[k][1], transforms[i].M[k][2], transforms[i].M[k][3]));
			}
			//C - Add vertex struct to vertex array
			vtex.Add({matRows[0],matRows[1],matRows[2],matRows[3],vertices[i],scales[i],FVector4()});
        }

}

TArray<FVector> FCustomDataTextureGenerationModel::GetVerticesFromSkellieMesh(USkeletalMeshComponent* comp) {
    TArray<FVector> verts;
    if (!comp->IsValidLowLevel()) return verts;
    if (!comp) return verts;
    if (!comp->GetSkeletalMeshRenderData()) return verts;

	if (!comp->GetAnimInstance()) return verts;
	
	comp->GetAnimInstance()->InitializeAnimation();

    TArray<FFinalSkinVertex> sVerts;
    comp->GetCPUSkinnedVertices(sVerts, 0);

    // Output only vertex position, not tangents or UVs.
    for (auto& v : sVerts) {
        verts.Add(FVector(v.Position));
    }
    return verts;
}

TArray<uint32> FCustomDataTextureGenerationModel::GetTrisFromSkellieMesh(USkeletalMeshComponent* comp) {

    TArray<uint32> verts;
    if (!comp->IsValidLowLevel()) return verts;
    if (!comp) return verts;
    FSkeletalMeshRenderData* data = comp->GetSkeletalMeshRenderData();
    if (!data) return verts;

    FMultiSizeIndexContainerData indexData;
    data->LODRenderData[0].MultiSizeIndexContainer.GetIndexBufferData(indexData);
    for (int i = 0; i < indexData.Indices.Num(); i++) {
        verts.Add(indexData.Indices[i]);
    }
    return verts;
}

TArray<FVector> FCustomDataTextureGenerationModel::GetVerticesFromStaticMesh(UStaticMeshComponent* comp) {
    TArray<FVector> verts;
    if (!comp->IsValidLowLevel()) return verts;
    if (!comp) return verts;
    if (!comp->GetStaticMesh()) return verts;
    if (!comp->GetStaticMesh()->RenderData) return verts;

    if (comp->GetStaticMesh()->RenderData->LODResources.Num() > 0)
    {

        FPositionVertexBuffer* VertexBuffer = &comp->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
        if (VertexBuffer)
        {

            const int32 VertexCount = VertexBuffer->GetNumVertices();
            for (int32 Index = 0; Index < VertexCount; Index++)
            {
                //This is in the Static Mesh Actor Class, so it is location and tranform of the SMActor
                const FVector pos = VertexBuffer->VertexPosition(Index);
                verts.Add(pos);
            }
        }
    }
    return verts;
}

TArray<uint32> FCustomDataTextureGenerationModel::GetTrisFromStaticMesh(UStaticMeshComponent* comp) {

    TArray<uint32> verts;
    if (!comp->IsValidLowLevel()) return verts;
    if (!comp) return verts;
    if (!comp->GetStaticMesh()) return verts;
    if (!comp->GetStaticMesh()->RenderData) return verts;

    if (comp->GetStaticMesh()->RenderData->LODResources.Num() > 0)
    {

        FRawStaticIndexBuffer* indexBuffer = &comp->GetStaticMesh()->RenderData->LODResources[0].IndexBuffer;
		if (indexBuffer)
		{
			 indexBuffer->GetCopy(verts);
		}
    }
    return verts;
}
void FCustomDataTextureGenerationModel::DrawGeometryToRenderTarget(
    UWorld* World,
    UTextureRenderTarget2D* OutputRenderTarget)
{
    check(IsInGameThread());
	(this)->BuildArrays();
	
    // Output.
    FCompiledCDTGModel CompiledModel;
	CompiledModel.vtex = TArray<FVertex>(this->vtex);
	CompiledModel.indices = TArray<uint32>(this->triangles);
    CompiledModel.ProjMatrix = this->PROJMATRIX;
    CompiledModel.ViewMatrix = this->VIEWMATRIX;
    const FName TextureRenderTargetName = OutputRenderTarget->GetFName();
    FTextureRenderTargetResource* TextureRenderTargetResource = OutputRenderTarget->GameThread_GetRenderTargetResource();

    ERHIFeatureLevel::Type FeatureLevel = World->Scene->GetFeatureLevel();

    ENQUEUE_RENDER_COMMAND(CaptureCommand)(
        [CompiledModel, TextureRenderTargetResource, TextureRenderTargetName, FeatureLevel](FRHICommandListImmediate& RHICmdList)
        {
            DrawCustomDataToRenderTarget_RenderThread(
                RHICmdList,
                CompiledModel,
                TextureRenderTargetName,
                TextureRenderTargetResource,
                FeatureLevel);
        }
    );
}