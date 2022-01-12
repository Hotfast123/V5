// Fill out your copyright notice in the Description page of Project Settings.

#include "Sliceable_Object.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Public/EngineGlobals.h"

class UStaticMesh;
class UStaticMeshComponent;
class UProceduralMeshComponent;
class EProcMesh;

// Sets default values
ASliceable_Object::ASliceable_Object()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
//void ASliceable_Object::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

// Called every frame
//void ASliceable_Object::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void ASliceable_Object::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	void SliceProceduralMesh(UProceduralMeshComponent * OtherInProcMesh, FVector PlanePosition, FVector PlaneNormal, bool bCreatOtherHalf, UProceduralMeshComponent * &OutOtherHalfProcMesh, EProcMesh CapOption, UMaterialInterface * CapMaterial);
}

