// Elisabeth Pring Copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void ClosedDoor(float DeltaTime);

	private:

	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float TargetYaw = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlates;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;

	float DoorLastOpened = 0.f;
	float DoorClosedDelay = .7f;

		 
};
