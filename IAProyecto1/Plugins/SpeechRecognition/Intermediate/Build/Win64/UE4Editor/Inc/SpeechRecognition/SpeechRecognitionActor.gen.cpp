// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/SpeechRecognition.h"
#include "Public/SpeechRecognitionActor.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpeechRecognitionActor() {}
// Cross Module References
	SPEECHRECOGNITION_API UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_UnknownPhraseSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SpeechRecognition();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_WordsSpokenSignature__DelegateSignature();
	SPEECHRECOGNITION_API UScriptStruct* Z_Construct_UScriptStruct_FRecognisedPhrases();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_StoppedSpeakingSignature__DelegateSignature();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_StartedSpeakingSignature__DelegateSignature();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_EnableGrammarMode();
	SPEECHRECOGNITION_API UClass* Z_Construct_UClass_ASpeechRecognitionActor();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_EnableKeywordMode();
	SPEECHRECOGNITION_API UScriptStruct* Z_Construct_UScriptStruct_FRecognitionPhrase();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_EnableLanguageModel();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_GetCurrentVolume();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_Init();
	SPEECHRECOGNITION_API UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_SetConfigParam();
	SPEECHRECOGNITION_API UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_Shutdown();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_StartedSpeaking_method();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_StoppedSpeaking_method();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_UnknownPhrase_method();
	SPEECHRECOGNITION_API UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_WordsSpoken_method();
	SPEECHRECOGNITION_API UClass* Z_Construct_UClass_ASpeechRecognitionActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_UnknownPhraseSignature__DelegateSignature()
	{
		UObject* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UnknownPhraseSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00130000, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_WordsSpokenSignature__DelegateSignature()
	{
		struct _Script_SpeechRecognition_eventWordsSpokenSignature_Parms
		{
			FRecognisedPhrases Text;
		};
		UObject* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("WordsSpokenSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00130000, 65535, sizeof(_Script_SpeechRecognition_eventWordsSpokenSignature_Parms));
			UProperty* NewProp_Text = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Text"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(Text, _Script_SpeechRecognition_eventWordsSpokenSignature_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FRecognisedPhrases());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_StoppedSpeakingSignature__DelegateSignature()
	{
		UObject* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("StoppedSpeakingSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00130000, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_SpeechRecognition_StartedSpeakingSignature__DelegateSignature()
	{
		UObject* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("StartedSpeakingSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00130000, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	void ASpeechRecognitionActor::StaticRegisterNativesASpeechRecognitionActor()
	{
		UClass* Class = ASpeechRecognitionActor::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "EnableGrammarMode", (Native)&ASpeechRecognitionActor::execEnableGrammarMode },
			{ "EnableKeywordMode", (Native)&ASpeechRecognitionActor::execEnableKeywordMode },
			{ "EnableLanguageModel", (Native)&ASpeechRecognitionActor::execEnableLanguageModel },
			{ "GetCurrentVolume", (Native)&ASpeechRecognitionActor::execGetCurrentVolume },
			{ "Init", (Native)&ASpeechRecognitionActor::execInit },
			{ "SetConfigParam", (Native)&ASpeechRecognitionActor::execSetConfigParam },
			{ "Shutdown", (Native)&ASpeechRecognitionActor::execShutdown },
			{ "StartedSpeaking_method", (Native)&ASpeechRecognitionActor::execStartedSpeaking_method },
			{ "StoppedSpeaking_method", (Native)&ASpeechRecognitionActor::execStoppedSpeaking_method },
			{ "UnknownPhrase_method", (Native)&ASpeechRecognitionActor::execUnknownPhrase_method },
			{ "WordsSpoken_method", (Native)&ASpeechRecognitionActor::execWordsSpoken_method },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_EnableGrammarMode()
	{
		struct SpeechRecognitionActor_eventEnableGrammarMode_Parms
		{
			FString grammarName;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EnableGrammarMode"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpeechRecognitionActor_eventEnableGrammarMode_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SpeechRecognitionActor_eventEnableGrammarMode_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SpeechRecognitionActor_eventEnableGrammarMode_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SpeechRecognitionActor_eventEnableGrammarMode_Parms), sizeof(bool), true);
			UProperty* NewProp_grammarName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("grammarName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(grammarName, SpeechRecognitionActor_eventEnableGrammarMode_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Audio"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Enable Grammar Mode"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Speech Recognition Mode"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_EnableKeywordMode()
	{
		struct SpeechRecognitionActor_eventEnableKeywordMode_Parms
		{
			TArray<FRecognitionPhrase> wordList;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EnableKeywordMode"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpeechRecognitionActor_eventEnableKeywordMode_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SpeechRecognitionActor_eventEnableKeywordMode_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SpeechRecognitionActor_eventEnableKeywordMode_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SpeechRecognitionActor_eventEnableKeywordMode_Parms), sizeof(bool), true);
			UProperty* NewProp_wordList = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("wordList"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(wordList, SpeechRecognitionActor_eventEnableKeywordMode_Parms), 0x0010000000000080);
			UProperty* NewProp_wordList_Inner = new(EC_InternalUseOnlyConstructor, NewProp_wordList, TEXT("wordList"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FRecognitionPhrase());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Audio"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Enable Keyword Mode"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Speech Recognition Mode"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Methods to switch recognition modes"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_EnableLanguageModel()
	{
		struct SpeechRecognitionActor_eventEnableLanguageModel_Parms
		{
			FString languageModel;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EnableLanguageModel"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpeechRecognitionActor_eventEnableLanguageModel_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SpeechRecognitionActor_eventEnableLanguageModel_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SpeechRecognitionActor_eventEnableLanguageModel_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SpeechRecognitionActor_eventEnableLanguageModel_Parms), sizeof(bool), true);
			UProperty* NewProp_languageModel = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("languageModel"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(languageModel, SpeechRecognitionActor_eventEnableLanguageModel_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Audio"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Enable Language Model Mode"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Speech Recognition Mode"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_GetCurrentVolume()
	{
		struct SpeechRecognitionActor_eventGetCurrentVolume_Parms
		{
			int32 ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetCurrentVolume"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpeechRecognitionActor_eventGetCurrentVolume_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ReturnValue, SpeechRecognitionActor_eventGetCurrentVolume_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Audio"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("GetCurrentVolume"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Speech Recognition Volume"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Basic functions"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_Init()
	{
		struct SpeechRecognitionActor_eventInit_Parms
		{
			ESpeechRecognitionLanguage language;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Init"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpeechRecognitionActor_eventInit_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SpeechRecognitionActor_eventInit_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SpeechRecognitionActor_eventInit_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SpeechRecognitionActor_eventInit_Parms), sizeof(bool), true);
			UProperty* NewProp_language = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("language"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(language, SpeechRecognitionActor_eventInit_Parms), 0x0010000000000080, Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage());
			UProperty* NewProp_language_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_language, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Audio"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Init"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Speech Recognition Init"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_SetConfigParam()
	{
		struct SpeechRecognitionActor_eventSetConfigParam_Parms
		{
			FString param;
			ESpeechRecognitionParamType type;
			FString value;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetConfigParam"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpeechRecognitionActor_eventSetConfigParam_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SpeechRecognitionActor_eventSetConfigParam_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SpeechRecognitionActor_eventSetConfigParam_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SpeechRecognitionActor_eventSetConfigParam_Parms), sizeof(bool), true);
			UProperty* NewProp_value = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("value"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(value, SpeechRecognitionActor_eventSetConfigParam_Parms), 0x0010000000000080);
			UProperty* NewProp_type = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("type"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(type, SpeechRecognitionActor_eventSetConfigParam_Parms), 0x0010000000000080, Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType());
			UProperty* NewProp_type_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_type, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_param = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("param"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(param, SpeechRecognitionActor_eventSetConfigParam_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Audio"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("SetConfigParam"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Speech Recognition Set Config Param"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_Shutdown()
	{
		struct SpeechRecognitionActor_eventShutdown_Parms
		{
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Shutdown"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SpeechRecognitionActor_eventShutdown_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SpeechRecognitionActor_eventShutdown_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SpeechRecognitionActor_eventShutdown_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SpeechRecognitionActor_eventShutdown_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Audio"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Shutdown"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Speech Recognition Shutdown"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_StartedSpeaking_method()
	{
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("StartedSpeaking_method"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_StoppedSpeaking_method()
	{
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("StoppedSpeaking_method"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_UnknownPhrase_method()
	{
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UnknownPhrase_method"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASpeechRecognitionActor_WordsSpoken_method()
	{
		struct SpeechRecognitionActor_eventWordsSpoken_method_Parms
		{
			FRecognisedPhrases phrases;
		};
		UObject* Outer = Z_Construct_UClass_ASpeechRecognitionActor();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("WordsSpoken_method"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x00020401, 65535, sizeof(SpeechRecognitionActor_eventWordsSpoken_method_Parms));
			UProperty* NewProp_phrases = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("phrases"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(phrases, SpeechRecognitionActor_eventWordsSpoken_method_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FRecognisedPhrases());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Callback events"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASpeechRecognitionActor_NoRegister()
	{
		return ASpeechRecognitionActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ASpeechRecognitionActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_SpeechRecognition();
			OuterClass = ASpeechRecognitionActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_EnableGrammarMode());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_EnableKeywordMode());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_EnableLanguageModel());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_GetCurrentVolume());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_Init());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_SetConfigParam());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_Shutdown());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_StartedSpeaking_method());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_StoppedSpeaking_method());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_UnknownPhrase_method());
				OuterClass->LinkChild(Z_Construct_UFunction_ASpeechRecognitionActor_WordsSpoken_method());

				UProperty* NewProp_OnStoppedSpeaking = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OnStoppedSpeaking"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(OnStoppedSpeaking, ASpeechRecognitionActor), 0x0010000010080000, Z_Construct_UDelegateFunction_SpeechRecognition_StoppedSpeakingSignature__DelegateSignature());
				UProperty* NewProp_OnStartedSpeaking = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OnStartedSpeaking"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(OnStartedSpeaking, ASpeechRecognitionActor), 0x0010000010080000, Z_Construct_UDelegateFunction_SpeechRecognition_StartedSpeakingSignature__DelegateSignature());
				UProperty* NewProp_OnUnknownPhrase = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OnUnknownPhrase"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(OnUnknownPhrase, ASpeechRecognitionActor), 0x0010000010080000, Z_Construct_UDelegateFunction_SpeechRecognition_UnknownPhraseSignature__DelegateSignature());
				UProperty* NewProp_OnWordsSpoken = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OnWordsSpoken"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(OnWordsSpoken, ASpeechRecognitionActor), 0x0010000010080000, Z_Construct_UDelegateFunction_SpeechRecognition_WordsSpokenSignature__DelegateSignature());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_EnableGrammarMode(), "EnableGrammarMode"); // 4045337101
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_EnableKeywordMode(), "EnableKeywordMode"); // 2612061051
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_EnableLanguageModel(), "EnableLanguageModel"); // 746162356
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_GetCurrentVolume(), "GetCurrentVolume"); // 143242784
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_Init(), "Init"); // 3436300367
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_SetConfigParam(), "SetConfigParam"); // 2650882594
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_Shutdown(), "Shutdown"); // 556915352
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_StartedSpeaking_method(), "StartedSpeaking_method"); // 3770189855
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_StoppedSpeaking_method(), "StoppedSpeaking_method"); // 1997226654
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_UnknownPhrase_method(), "UnknownPhrase_method"); // 2078318261
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASpeechRecognitionActor_WordsSpoken_method(), "WordsSpoken_method"); // 3813838403
				static TCppClassTypeInfo<TCppClassTypeTraits<ASpeechRecognitionActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SpeechRecognitionActor.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
				MetaData->SetValue(NewProp_OnStoppedSpeaking, TEXT("Category"), TEXT("Audio"));
				MetaData->SetValue(NewProp_OnStoppedSpeaking, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
				MetaData->SetValue(NewProp_OnStartedSpeaking, TEXT("Category"), TEXT("Audio"));
				MetaData->SetValue(NewProp_OnStartedSpeaking, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
				MetaData->SetValue(NewProp_OnUnknownPhrase, TEXT("Category"), TEXT("Audio"));
				MetaData->SetValue(NewProp_OnUnknownPhrase, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
				MetaData->SetValue(NewProp_OnWordsSpoken, TEXT("Category"), TEXT("Audio"));
				MetaData->SetValue(NewProp_OnWordsSpoken, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognitionActor.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpeechRecognitionActor, 788513671);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpeechRecognitionActor(Z_Construct_UClass_ASpeechRecognitionActor, &ASpeechRecognitionActor::StaticClass, TEXT("/Script/SpeechRecognition"), TEXT("ASpeechRecognitionActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpeechRecognitionActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
