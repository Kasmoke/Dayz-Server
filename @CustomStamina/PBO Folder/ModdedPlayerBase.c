modded class PlayerBase
{
    override void UpdateStamina(float deltaTime, float modifier = 1.0)
    {
        super.UpdateStamina(deltaTime, modifier);
        
        if (!m_StaminaHandler)
            return;
        
        float weight = GetWeight();
        
        // Vanilla default
        float defaultThreshold = 6000.0;
        
        float multiplier = CustomStaminaSettings.Get().StaminaWeightImpactMultiplier;
        
        float effectiveThreshold = defaultThreshold / multiplier;
        
        float weightPenalty = weight / effectiveThreshold;
        
        weightPenalty = Math.Clamp(weightPenalty, 0.0, 2.0);
        
        m_StaminaHandler.DecreaseStamina(deltaTime * weightPenalty);
    }
}
