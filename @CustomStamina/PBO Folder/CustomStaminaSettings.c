class CustomStaminaSettings
{
    static ref CustomStaminaSettings m_Instance;
    
    float StaminaWeightImpactMultiplier = 0.65; // Default = 0.65 (~35% stamina reduction)
    
    void CustomStaminaSettings()
    {
        // Constructor
    }
    
    static CustomStaminaSettings Get()
    {
        if (!m_Instance)
            m_Instance = Load();
        return m_Instance;
    }
    
    static CustomStaminaSettings Load()
    {
        CustomStaminaSettings settings = new CustomStaminaSettings();
        if (FileExist("$profile:CustomStaminaSettings.json"))
        {
            JsonFileLoader<CustomStaminaSettings>.JsonLoadFile("$profile:CustomStaminaSettings.json", settings);
        }
        else
        {
            settings.Save(); // Save default settings if file doesn't exist
        }
        return settings;
    }
    
    void Save()
    {
        JsonFileLoader<CustomStaminaSettings>.JsonSaveFile("$profile:CustomStaminaSettings.json", this);
    }
}
