#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomDataAPI.h"

#include "Components/MeshComponent.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Engine/StaticMesh.h"
#include "PrimitiveSceneProxy.h"
#include "StaticMeshDescription.h"
#include "Rendering/StaticMeshVertexBuffer.h"

#include "RHICommandList.h"
#include "PrimitiveSceneProxy.h"
#include "CustomDataBlueprintLibrary.generated.h"





UCLASS(MinimalAPI)
class UCustomDataBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "CustomDataTexture",meta = (WorldContext = "WorldContextObject"))
		static void DrawGeometryToRenderTarget(const UObject* WorldContextObject, UPARAM(ref) FCustomDataTextureGenerationModel& model);
	
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (CustomDataTextureGenerationModel)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "CustomDataTexture")
		static bool EqualEqual_CompareLensDistortionModels(
			const FCustomDataTextureGenerationModel& A,
			const FCustomDataTextureGenerationModel& B)
	{
		return A == B;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "NotEqual (CustomDataTextureGenerationModel)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "CustomDataTextureGeneration")
		static bool NotEqual_CompareCustomDataTextureGenerationModels(
			const FCustomDataTextureGenerationModel& A,
			const FCustomDataTextureGenerationModel& B)
	{
		return A != B;
	}
	
};