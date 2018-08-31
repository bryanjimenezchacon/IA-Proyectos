// Fill out your copyright notice in the Description page of Project Settings.

#include "Sphinx_UE4_Demo.h"
#include "SpeechRecogTestActor.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
ASpeechRecogTestActor::ASpeechRecogTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create speech recognition actor
	childActor = CreateDefaultSubobject<UChildActorComponent>("ChildActor");
	childActor->SetChildActorClass(ASpeechRecognitionActor::StaticClass());
	childActor->CreateChildActor();
	recognitionActor = (ASpeechRecognitionActor*)childActor->GetChildActor();

}

// Called when speech is detected
void ASpeechRecogTestActor::OnWordSpoken(FRecognisedPhrases phrases)
{
	TArray<FString> phraseArray = phrases.phrases;
	FString phrase;
	for (auto& phrase : phraseArray)
	{
		print(phrase);
	}
	print("ASpeechRecogTestActor:Init success");
}

// Called when the game starts or when spawned
void ASpeechRecogTestActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Hook to internal callback methods
	recognitionActor->OnWordsSpoken.AddDynamic(this, &ASpeechRecogTestActor::OnWordSpoken);

	// Start the listener, with language English
	bool result = recognitionActor->Init(ESpeechRecognitionLanguage::VE_Spanish);
	if (result) {
		print("ASpeechRecogTestActor:Init success");

		// set config params
		recognitionActor->SetConfigParam("-vad_prespeech", ESpeechRecognitionParamType::VE_INTEGER, "10");
		recognitionActor->SetConfigParam("-vad_postspeech", ESpeechRecognitionParamType::VE_INTEGER, "10");
		recognitionActor->SetConfigParam("-agc", ESpeechRecognitionParamType::VE_STRING, "noise");
		recognitionActor->SetConfigParam("-beam", ESpeechRecognitionParamType::VE_FLOAT, "1e-60");

		// add phrases to be recognised
		TArray<FRecognitionPhrase> wordList;
		wordList.Add(FRecognitionPhrase(FString("hello world"), EPhraseRecognitionTolerance::VE_5));
		wordList.Add(FRecognitionPhrase(FString("open door"), EPhraseRecognitionTolerance::VE_3));
		recognitionActor->EnableKeywordMode(wordList);
	}
	else {
		print("ASpeechRecogTestActor:Init failure");
	}
}

// Call shutdown on listener
void ASpeechRecogTestActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	recognitionActor->Shutdown();
}

// Called every frame
void ASpeechRecogTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

