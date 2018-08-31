// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRecognisedPhrases;
enum class ESpeechRecognitionParamType : uint8;
enum class ESpeechRecognitionLanguage : uint8;
struct FRecognitionPhrase;
#ifdef SPEECHRECOGNITION_SpeechRecognitionActor_generated_h
#error "SpeechRecognitionActor.generated.h already included, missing '#pragma once' in SpeechRecognitionActor.h"
#endif
#define SPEECHRECOGNITION_SpeechRecognitionActor_generated_h

#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_12_DELEGATE \
static inline void FUnknownPhraseSignature_DelegateWrapper(const FMulticastScriptDelegate& UnknownPhraseSignature) \
{ \
	UnknownPhraseSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_11_DELEGATE \
struct _Script_SpeechRecognition_eventWordsSpokenSignature_Parms \
{ \
	FRecognisedPhrases Text; \
}; \
static inline void FWordsSpokenSignature_DelegateWrapper(const FMulticastScriptDelegate& WordsSpokenSignature, FRecognisedPhrases Text) \
{ \
	_Script_SpeechRecognition_eventWordsSpokenSignature_Parms Parms; \
	Parms.Text=Text; \
	WordsSpokenSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_10_DELEGATE \
static inline void FStoppedSpeakingSignature_DelegateWrapper(const FMulticastScriptDelegate& StoppedSpeakingSignature) \
{ \
	StoppedSpeakingSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_9_DELEGATE \
static inline void FStartedSpeakingSignature_DelegateWrapper(const FMulticastScriptDelegate& StartedSpeakingSignature) \
{ \
	StartedSpeakingSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStoppedSpeaking_method) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StoppedSpeaking_method(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartedSpeaking_method) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartedSpeaking_method(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnknownPhrase_method) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UnknownPhrase_method(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWordsSpoken_method) \
	{ \
		P_GET_STRUCT(FRecognisedPhrases,Z_Param_phrases); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->WordsSpoken_method(Z_Param_phrases); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShutdown) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->Shutdown(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetConfigParam) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_param); \
		P_GET_ENUM(ESpeechRecognitionParamType,Z_Param_type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->SetConfigParam(Z_Param_param,ESpeechRecognitionParamType(Z_Param_type),Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInit) \
	{ \
		P_GET_ENUM(ESpeechRecognitionLanguage,Z_Param_language); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->Init(ESpeechRecognitionLanguage(Z_Param_language)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetCurrentVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLanguageModel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_languageModel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->EnableLanguageModel(Z_Param_languageModel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableGrammarMode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_grammarName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->EnableGrammarMode(Z_Param_grammarName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableKeywordMode) \
	{ \
		P_GET_TARRAY(FRecognitionPhrase,Z_Param_wordList); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->EnableKeywordMode(Z_Param_wordList); \
		P_NATIVE_END; \
	}


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStoppedSpeaking_method) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StoppedSpeaking_method(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartedSpeaking_method) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartedSpeaking_method(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnknownPhrase_method) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UnknownPhrase_method(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWordsSpoken_method) \
	{ \
		P_GET_STRUCT(FRecognisedPhrases,Z_Param_phrases); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->WordsSpoken_method(Z_Param_phrases); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShutdown) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->Shutdown(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetConfigParam) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_param); \
		P_GET_ENUM(ESpeechRecognitionParamType,Z_Param_type); \
		P_GET_PROPERTY(UStrProperty,Z_Param_value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->SetConfigParam(Z_Param_param,ESpeechRecognitionParamType(Z_Param_type),Z_Param_value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInit) \
	{ \
		P_GET_ENUM(ESpeechRecognitionLanguage,Z_Param_language); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->Init(ESpeechRecognitionLanguage(Z_Param_language)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentVolume) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetCurrentVolume(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableLanguageModel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_languageModel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->EnableLanguageModel(Z_Param_languageModel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableGrammarMode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_grammarName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->EnableGrammarMode(Z_Param_grammarName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableKeywordMode) \
	{ \
		P_GET_TARRAY(FRecognitionPhrase,Z_Param_wordList); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->EnableKeywordMode(Z_Param_wordList); \
		P_NATIVE_END; \
	}


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpeechRecognitionActor(); \
	friend SPEECHRECOGNITION_API class UClass* Z_Construct_UClass_ASpeechRecognitionActor(); \
public: \
	DECLARE_CLASS(ASpeechRecognitionActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SpeechRecognition"), NO_API) \
	DECLARE_SERIALIZER(ASpeechRecognitionActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_INCLASS \
private: \
	static void StaticRegisterNativesASpeechRecognitionActor(); \
	friend SPEECHRECOGNITION_API class UClass* Z_Construct_UClass_ASpeechRecognitionActor(); \
public: \
	DECLARE_CLASS(ASpeechRecognitionActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/SpeechRecognition"), NO_API) \
	DECLARE_SERIALIZER(ASpeechRecognitionActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpeechRecognitionActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpeechRecognitionActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpeechRecognitionActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpeechRecognitionActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpeechRecognitionActor(ASpeechRecognitionActor&&); \
	NO_API ASpeechRecognitionActor(const ASpeechRecognitionActor&); \
public:


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpeechRecognitionActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpeechRecognitionActor(ASpeechRecognitionActor&&); \
	NO_API ASpeechRecognitionActor(const ASpeechRecognitionActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpeechRecognitionActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpeechRecognitionActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpeechRecognitionActor)


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_PRIVATE_PROPERTY_OFFSET
#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_14_PROLOG
#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_PRIVATE_PROPERTY_OFFSET \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_RPC_WRAPPERS \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_INCLASS \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_PRIVATE_PROPERTY_OFFSET \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_INCLASS_NO_PURE_DECLS \
	Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Sphinx_UE4_Demo_Plugins_SpeechRecognition_Source_SpeechRecognition_Public_SpeechRecognitionActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
