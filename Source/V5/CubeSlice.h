// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KismetProceduralMeshLibrary.h"
#include "GameFramework/Actor.h"
#include "CubeSlice.generated.h"

UCLASS()
class V5_API ACubeSlice : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeSlice();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SliceCube;

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProMesh;

	//bool CreateCollsion = true;

	//Example code 
	//UFUNCTION(BlueprintCallable, Category = "Components|ProceduralMesh")
	//void CopyProceduralMeshFromStaticMeshComponent(UStaticMeshComponent* StaticMeshComponent, int32 LODIndex, UProceduralMeshComponent* ProcMeshComponent, bool bCreateCollision);
	//void SliceProceduralMesh(UProceduralMeshComponent* OtherInProcMesh, FVector PlanePosition, FVector PlaneNormal, bool bCreatOtherHalf, UProceduralMeshComponent*& OutOtherHalfProcMesh, EProcMesh CapOption, UMaterialInterface* CapMaterial);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};