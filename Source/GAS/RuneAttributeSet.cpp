// Fill out your copyright notice in the Description page of Project Settings.


#include "RuneAttributeSet.h"

#include "Net/UnrealNetwork.h"

URuneAttributeSet::URuneAttributeSet()
{
}

void URuneAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Stemina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Energy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URuneAttributeSet, Hydration, COND_None, REPNOTIFY_Always);
}

void URuneAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Health, OldHealth);
}

void URuneAttributeSet::OnRep_Stemina(const FGameplayAttributeData& OldStemina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Stemina, OldStemina);
}

void URuneAttributeSet::OnRep_Energy(const FGameplayAttributeData& OldEnergy)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Energy, OldEnergy);
}

void URuneAttributeSet::OnRep_Hydration(const FGameplayAttributeData& OldHydration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URuneAttributeSet, Hydration, OldHydration);
}
