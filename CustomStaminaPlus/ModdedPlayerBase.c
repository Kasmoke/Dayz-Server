modded class PlayerBase
{
    override void UpdateStamina(float deltaTime, float modifier = 1.0)
    {
        super.UpdateStamina(deltaTime, modifier);
        
        if (!m_StaminaHandler)
            return;

        float weight = GetWeight();
        
        // DayZ vanilla default threshold: 6000g (6kg)
        float defaultThreshold = 6000.0;

        // Apply multiplier (lower multiplier = less stamina penalty)
        float effectiveThreshold = defaultThreshold / CustomStaminaSettings.StaminaWeightImpactMultiplier;
        
        float weightPenalty = weight / effectiveThreshold;

        // Safe clamp to prevent extreme values
        weightPenalty = Math.Clamp(weightPenalty, 0.0, 2.0);

        m_StaminaHandler.DecreaseStamina(deltaTime * weightPenalty);
    }
}
