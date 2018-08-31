// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/SpeechRecognition.h"
#include "Public/SpeechRecognition.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpeechRecognition() {}
// Cross Module References
	SPEECHRECOGNITION_API UEnum* Z_Construct_UEnum_SpeechRecognition_EPhraseRecognitionTolerance();
	UPackage* Z_Construct_UPackage__Script_SpeechRecognition();
	SPEECHRECOGNITION_API UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage();
	SPEECHRECOGNITION_API UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType();
	SPEECHRECOGNITION_API UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionMode();
	SPEECHRECOGNITION_API UScriptStruct* Z_Construct_UScriptStruct_FRecognitionPhrase();
	SPEECHRECOGNITION_API UScriptStruct* Z_Construct_UScriptStruct_FRecognisedPhrases();
// End Cross Module References
static UEnum* EPhraseRecognitionTolerance_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_SpeechRecognition_EPhraseRecognitionTolerance, Z_Construct_UPackage__Script_SpeechRecognition(), TEXT("EPhraseRecognitionTolerance"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPhraseRecognitionTolerance(EPhraseRecognitionTolerance_StaticEnum, TEXT("/Script/SpeechRecognition"), TEXT("EPhraseRecognitionTolerance"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_SpeechRecognition_EPhraseRecognitionTolerance()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		extern uint32 Get_Z_Construct_UEnum_SpeechRecognition_EPhraseRecognitionTolerance_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPhraseRecognitionTolerance"), 0, Get_Z_Construct_UEnum_SpeechRecognition_EPhraseRecognitionTolerance_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EPhraseRecognitionTolerance"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_1"), 0);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_2"), 1);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_3"), 2);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_4"), 3);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_5"), 4);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_6"), 5);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_7"), 6);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_8"), 7);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_9"), 8);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_10"), 9);
			EnumNames.Emplace(TEXT("EPhraseRecognitionTolerance::VE_MAX"), 10);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EPhraseRecognitionTolerance");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_1.DisplayName"), TEXT("V1"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_10.DisplayName"), TEXT("V10"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_2.DisplayName"), TEXT("V2"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_3.DisplayName"), TEXT("V3"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_4.DisplayName"), TEXT("V4"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_5.DisplayName"), TEXT("V5"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_6.DisplayName"), TEXT("V6"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_7.DisplayName"), TEXT("V7"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_8.DisplayName"), TEXT("V8"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_9.DisplayName"), TEXT("V9"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_SpeechRecognition_EPhraseRecognitionTolerance_CRC() { return 3563084058U; }
static UEnum* ESpeechRecognitionLanguage_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage, Z_Construct_UPackage__Script_SpeechRecognition(), TEXT("ESpeechRecognitionLanguage"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESpeechRecognitionLanguage(ESpeechRecognitionLanguage_StaticEnum, TEXT("/Script/SpeechRecognition"), TEXT("ESpeechRecognitionLanguage"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		extern uint32 Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESpeechRecognitionLanguage"), 0, Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ESpeechRecognitionLanguage"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("ESpeechRecognitionLanguage::VE_English"), 0);
			EnumNames.Emplace(TEXT("ESpeechRecognitionLanguage::VE_Chinese"), 1);
			EnumNames.Emplace(TEXT("ESpeechRecognitionLanguage::VE_French"), 2);
			EnumNames.Emplace(TEXT("ESpeechRecognitionLanguage::VE_Spanish"), 3);
			EnumNames.Emplace(TEXT("ESpeechRecognitionLanguage::VE_Russian"), 4);
			EnumNames.Emplace(TEXT("ESpeechRecognitionLanguage::VE_MAX"), 5);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("ESpeechRecognitionLanguage");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Chinese.DisplayName"), TEXT("Chinese"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_English.DisplayName"), TEXT("English"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_French.DisplayName"), TEXT("French"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Russian.DisplayName"), TEXT("Russian"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_Spanish.DisplayName"), TEXT("Spanish"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionLanguage_CRC() { return 3778480281U; }
static UEnum* ESpeechRecognitionParamType_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType, Z_Construct_UPackage__Script_SpeechRecognition(), TEXT("ESpeechRecognitionParamType"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESpeechRecognitionParamType(ESpeechRecognitionParamType_StaticEnum, TEXT("/Script/SpeechRecognition"), TEXT("ESpeechRecognitionParamType"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		extern uint32 Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESpeechRecognitionParamType"), 0, Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ESpeechRecognitionParamType"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("ESpeechRecognitionParamType::VE_FLOAT"), 0);
			EnumNames.Emplace(TEXT("ESpeechRecognitionParamType::VE_BOOLEAN"), 1);
			EnumNames.Emplace(TEXT("ESpeechRecognitionParamType::VE_STRING"), 2);
			EnumNames.Emplace(TEXT("ESpeechRecognitionParamType::VE_INTEGER"), 3);
			EnumNames.Emplace(TEXT("ESpeechRecognitionParamType::VE_MAX"), 4);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("ESpeechRecognitionParamType");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_BOOLEAN.DisplayName"), TEXT("Boolean"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_FLOAT.DisplayName"), TEXT("Float"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_INTEGER.DisplayName"), TEXT("Integer"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_STRING.DisplayName"), TEXT("String"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionParamType_CRC() { return 3825768277U; }
static UEnum* ESpeechRecognitionMode_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionMode, Z_Construct_UPackage__Script_SpeechRecognition(), TEXT("ESpeechRecognitionMode"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESpeechRecognitionMode(ESpeechRecognitionMode_StaticEnum, TEXT("/Script/SpeechRecognition"), TEXT("ESpeechRecognitionMode"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionMode()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		extern uint32 Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionMode_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESpeechRecognitionMode"), 0, Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionMode_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ESpeechRecognitionMode"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("ESpeechRecognitionMode::VE_KEYWORD"), 0);
			EnumNames.Emplace(TEXT("ESpeechRecognitionMode::VE_GRAMMAR"), 1);
			EnumNames.Emplace(TEXT("ESpeechRecognitionMode::VE_LANGUAGE_MODEL"), 2);
			EnumNames.Emplace(TEXT("ESpeechRecognitionMode::VE_MAX"), 3);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("ESpeechRecognitionMode");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_GRAMMAR.DisplayName"), TEXT("Grammar"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_KEYWORD.DisplayName"), TEXT("Keyword Spotting"));
			MetaData->SetValue(ReturnEnum, TEXT("VE_LANGUAGE_MODEL.DisplayName"), TEXT("Language Model"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_SpeechRecognition_ESpeechRecognitionMode_CRC() { return 3122182770U; }
class UScriptStruct* FRecognitionPhrase::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SPEECHRECOGNITION_API uint32 Get_Z_Construct_UScriptStruct_FRecognitionPhrase_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRecognitionPhrase, Z_Construct_UPackage__Script_SpeechRecognition(), TEXT("RecognitionPhrase"), sizeof(FRecognitionPhrase), Get_Z_Construct_UScriptStruct_FRecognitionPhrase_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRecognitionPhrase(FRecognitionPhrase::StaticStruct, TEXT("/Script/SpeechRecognition"), TEXT("RecognitionPhrase"), false, nullptr, nullptr);
static struct FScriptStruct_SpeechRecognition_StaticRegisterNativesFRecognitionPhrase
{
	FScriptStruct_SpeechRecognition_StaticRegisterNativesFRecognitionPhrase()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RecognitionPhrase")),new UScriptStruct::TCppStructOps<FRecognitionPhrase>);
	}
} ScriptStruct_SpeechRecognition_StaticRegisterNativesFRecognitionPhrase;
	UScriptStruct* Z_Construct_UScriptStruct_FRecognitionPhrase()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		extern uint32 Get_Z_Construct_UScriptStruct_FRecognitionPhrase_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RecognitionPhrase"), sizeof(FRecognitionPhrase), Get_Z_Construct_UScriptStruct_FRecognitionPhrase_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RecognitionPhrase"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FRecognitionPhrase>, EStructFlags(0x00000001));
			UProperty* NewProp_tolerance = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("tolerance"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(tolerance, FRecognitionPhrase), 0x0010000000000004, Z_Construct_UEnum_SpeechRecognition_EPhraseRecognitionTolerance());
			UProperty* NewProp_tolerance_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_tolerance, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_phrase = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("phrase"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(phrase, FRecognitionPhrase), 0x0010000000000004);
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
			MetaData->SetValue(NewProp_tolerance, TEXT("Category"), TEXT("RecognitionPhrase"));
			MetaData->SetValue(NewProp_tolerance, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
			MetaData->SetValue(NewProp_phrase, TEXT("Category"), TEXT("RecognitionPhrase"));
			MetaData->SetValue(NewProp_phrase, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRecognitionPhrase_CRC() { return 2428288274U; }
class UScriptStruct* FRecognisedPhrases::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SPEECHRECOGNITION_API uint32 Get_Z_Construct_UScriptStruct_FRecognisedPhrases_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRecognisedPhrases, Z_Construct_UPackage__Script_SpeechRecognition(), TEXT("RecognisedPhrases"), sizeof(FRecognisedPhrases), Get_Z_Construct_UScriptStruct_FRecognisedPhrases_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRecognisedPhrases(FRecognisedPhrases::StaticStruct, TEXT("/Script/SpeechRecognition"), TEXT("RecognisedPhrases"), false, nullptr, nullptr);
static struct FScriptStruct_SpeechRecognition_StaticRegisterNativesFRecognisedPhrases
{
	FScriptStruct_SpeechRecognition_StaticRegisterNativesFRecognisedPhrases()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RecognisedPhrases")),new UScriptStruct::TCppStructOps<FRecognisedPhrases>);
	}
} ScriptStruct_SpeechRecognition_StaticRegisterNativesFRecognisedPhrases;
	UScriptStruct* Z_Construct_UScriptStruct_FRecognisedPhrases()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_SpeechRecognition();
		extern uint32 Get_Z_Construct_UScriptStruct_FRecognisedPhrases_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RecognisedPhrases"), sizeof(FRecognisedPhrases), Get_Z_Construct_UScriptStruct_FRecognisedPhrases_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RecognisedPhrases"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FRecognisedPhrases>, EStructFlags(0x00000001));
			UProperty* NewProp_phrases = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("phrases"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(phrases, FRecognisedPhrases), 0x0010000000000004);
			UProperty* NewProp_phrases_Inner = new(EC_InternalUseOnlyConstructor, NewProp_phrases, TEXT("phrases"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
			MetaData->SetValue(ReturnStruct, TEXT("ToolTip"), TEXT("Common structures and enumerations"));
			MetaData->SetValue(NewProp_phrases, TEXT("Category"), TEXT("RecognisedPhrases"));
			MetaData->SetValue(NewProp_phrases, TEXT("ModuleRelativePath"), TEXT("Public/SpeechRecognition.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRecognisedPhrases_CRC() { return 2370463932U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
