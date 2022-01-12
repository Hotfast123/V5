// Copyright Epic Games, Inc. All Rights Reserved.

#include "V5Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"

#include "CubeSlice.h"
#include "ObjectToSlice.h"

#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Public/EngineGlobals.h"
//#include "ProceduralMeshComponent.h"
//#include "KismetProceduralMeshLibrary.h"

class UStaticMesh;
class UStaticMeshComponent;
class UProceduralMeshComponent;
class EProcMesh;

AV5Projectile::AV5Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AV5Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AV5Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, TEXT("Hit"));
	
	//SliceProceduralMesh(ProMesh, FVector PlanePosition, FVector PlaneNormal, bool bCreatOtherHalf, UProceduralMeshComponent * &OutOtherHalfProcMesh, EProcMesh CapOption, UMaterialInterface * CapMaterial);
	
	//Simulate the physics for the new objects
	//void SetSimulatePhysics();
	GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, TEXT("SLICED"));
	
	/**
	 *	Slice the ProceduralMeshComponent (including simple convex collision) using a plane. Optionally create 'cap' geometry.
	 *	@param	InProcMesh				ProceduralMeshComponent to slice
	 *	@param	PlanePosition			Point on the plane to use for slicing, in world space
	 *	@param	PlaneNormal				Normal of plane used for slicing. Geometry on the positive side of the plane will be kept.
	 *	@param	bCreateOtherHalf		If true, an additional ProceduralMeshComponent (OutOtherHalfProcMesh) will be created using the other half of the sliced geometry
	 *	@param	OutOtherHalfProcMesh	If bCreateOtherHalf is set, this is the new component created. Its owner will be the same as the supplied InProcMesh.
	 *	@param	CapOption				If and how to create 'cap' geometry on the slicing plane
	 *	@param	CapMaterial				If creating a new section for the cap, assign this material to that section
	 */
	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		//Destroy();
	}
	//Destroy();
}