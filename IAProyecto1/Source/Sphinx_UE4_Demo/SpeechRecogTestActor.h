// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpeechRecognition.h"
#include "SpeechRecognitionActor.h"
#include "SpeechRecogTestActor.generated.h"

UCLASS()
class SPHINX_UE4_DEMO_API ASpeechRecogTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeechRecogTestActor();

protected:

	UPROPERTY()
	UChildActorComponent* childActor;

	UPROPERTY()
	ASpeechRecognitionActor* recognitionActor;

	UFUNCTION()
	void OnWordSpoken(FRecognisedPhrases phrases);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
