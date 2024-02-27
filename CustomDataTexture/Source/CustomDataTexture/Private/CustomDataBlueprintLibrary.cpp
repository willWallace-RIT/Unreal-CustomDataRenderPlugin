#include "CustomDataBlueprintLibrary.h"

UCustomDataBlueprintLibrary::UCustomDataBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{ }



void UCustomDataBlueprintLibrary::DrawGeometryToRenderTarget(const UObject* WorldContextObject, FCustomDataTextureGenerationModel& model) {
	model.DrawGeometryToRenderTarget((WorldContextObject->GetWorld()), model.renderTarget);
}
