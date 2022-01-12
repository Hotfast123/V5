// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectToSlice.h"

// Sets default values
AObjectToSlice::AObjectToSlice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Creating a standard root object.
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	
	// Controls whether the physics cooking should be done off the game thread. 
	// This should be used when collision geometry doesn't have to be immediately up to date (For example streaming in far away objects)
	//mesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AObjectToSlice::BeginPlay()
{
	Super::BeginPlay();
	//void CopyProceduralMeshFromStaticMeshComponent(UStaticMeshComponent* StaticMeshComponent, int32 LODIndex, UProceduralMeshComponent* ProcMeshComponent, bool bCreateCollision);
	//void SliceProceduralMesh(UProceduralMeshComponent* OtherInProcMesh, FVector PlanePosition, FVector PlaneNormal, bool bCreatOtherHalf, UProceduralMeshComponent*& OutOtherHalfProcMesh, EProcMesh CapOption, UMaterialInterface* CapMaterial);
}

// Called every frame
void AObjectToSlice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
void AObjectToSlice::PostActorCreated()
{
	Super::PostActorCreated();
	CreateTriangle();
}

// This is called when actor is already in level and map is opened
void AObjectToSlice::PostLoad()
{
	Super::PostLoad();
	CreateTriangle();
}

void AObjectToSlice::CreateTriangle()
{
	TArray<FVector> vertices; // Define diffrente points of the mesh and lets the program know how to aply the meshs to it 
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, 100, 0));
	vertices.Add(FVector(0, 0, 100));
	vertices.Add(FVector(0, 100, 100));

	TArray<int32> Triangles; //A buffer that points to vertices - saves memeory by not having duplicate vectors
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	Triangles.Add(3);
	Triangles.Add(2);
	Triangles.Add(1);

	TArray<FVector> normals; // Which way the surfaces are facing 
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	TArray<FVector2D> UV0; // Lets the 3d Render know how to aplly the meshs 
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	TArray<FProcMeshTangent> tangents; // 90 deegree angle to the normal
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> vertexColors; // Coulur to the vertices
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}