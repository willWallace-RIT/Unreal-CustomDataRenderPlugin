#pragma once

#include "CoreMinimal.h"
#include "Components/MeshComponent.h"

#include "RHIResources.h"
#include "RHICommandList.h"
#include "RHIStaticStates.h"
#include "RenderResource.h"
#include "Engine/TextureRenderTarget2D.h"
#include "CustomDataAPI.generated.h"
struct FVertex {
	FVector4 transformComp0;
	FVector4 transformComp1;
	FVector4 transformComp2;
	FVector4 transformComp3;
	FVector4 vertex;
	FVector scale;
	FVector4 color;
	
	
};

USTRUCT(BlueprintType)
struct FCustomDataTextureGenerationModel
{
	GENERATED_USTRUCT_BODY()
		FCustomDataTextureGenerationModel()
	{
	}
	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, Category = "CustomDataTexture")
		FMatrix VIEWMATRIX;
	
	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, Category = "CustomDataTexture")
		FMatrix PROJMATRIX;
	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, Category = "CustomDataTexture")
		TArray<AActor*> Actors;
	UPROPERTY(Interp, EditAnywhere, BlueprintReadWrite, Category = "CustomDataTexture")
		UTextureRenderTarget2D* renderTarget;
	TArray<FVector> vertices;
	TArray<uint32> triangles;
	TArray<FMatrix> transforms;
	TArray<FVector> scales;
	TArray<FVertex> vtex;
	//Not great with those tarray comparisons but its only so it'll work
	bool operator == (const FCustomDataTextureGenerationModel& Other) const {
		return (VIEWMATRIX == Other.VIEWMATRIX &&
			PROJMATRIX == Other.PROJMATRIX &&
			vertices == Other.vertices &&
			triangles == Other.triangles &&
			transforms == Other.transforms &&
			scales == Other.scales &&
			Actors == Other.Actors);
	}
	bool operator != (const FCustomDataTextureGenerationModel& Other) const {
		return !(*this == Other);
	}
	void BuildArrays();
	TArray<uint32> GetTrisFromStaticMesh(UStaticMeshComponent* comp);
	TArray<FVector> GetVerticesFromStaticMesh(UStaticMeshComponent* comp);
	TArray<uint32> GetTrisFromSkellieMesh(USkeletalMeshComponent* comp);
	TArray<FVector> GetVerticesFromSkellieMesh(USkeletalMeshComponent* comp);
	void DrawGeometryToRenderTarget(UWorld* world, class UTextureRenderTarget2D* OutputRenderTarget);

	
};
