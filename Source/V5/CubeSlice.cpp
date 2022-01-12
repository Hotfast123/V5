// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeSlice.h"
#include <ProceduralMeshComponent/Private/KismetProceduralMeshLibrary.cpp>
using namespace UKismetProceduralMeshLibrary;

class KismetProceduralMeshLibrary;


// Sets default values
ACubeSlice::ACubeSlice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SliceCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeSlice"));
	ProMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProMesh"));

	UKismetProceduralMeshLibrary::CopyProceduralMeshFromStaticMeshComponent(SliceCube, 0, ProMesh, true);

	//void CopyProceduralMeshFromStaticMeshComponent(UStaticMeshComponent* StaticMeshComponent, int32 LODIndex, UProceduralMeshComponent* ProcMeshComponent, bool bCreateCollision);
}

// Called when the game starts or when spawned
void ACubeSlice::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACubeSlice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



