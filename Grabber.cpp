// Copyright Elisabeth Pring 2022

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player viewpoint
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint
	(	OUT PlayerViewPointLocation, 
		OUT PlayerViewPointRotation
	);

	// UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"), 
	// 	*PlayerViewPointLocation.ToString(), 
	// 	*PlayerViewPointRotation.ToString()
	// );

	// draw a line from player showing the reach

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(0, 255, 0),
		false,
		0.f,
		0,
		5.f
	);

	// logging out to test
	
	// ray-cast out to a certain distance (reach)

	// see what it hits
}

