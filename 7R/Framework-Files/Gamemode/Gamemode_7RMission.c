class Gamemode_7RMission: SCR_BaseGameMode
{
	// Internal variables
	private ref AISpawnHandler iAISpawnHandler;
	private ref MissionManager iMissionManager;
	
	
	// Properties
	
	override void OnGameStart()
	{
		super.OnGameStart();
		
		// Move this to world editor?
		// Create spawn templates
		map<int, string> mapSpawnTemplates = new map<int, string>();
		// 1: Inf-squad (8 man, no AT/ no GL)
		mapSpawnTemplates.Set(1, "groupClassname");
		// 2: Inf-squad (8 man, AT/ no GL)
		mapSpawnTemplates.Set(2, "groupClassname");
		// 3: Inf-squad (8 man, no AT/ GL)
		mapSpawnTemplates.Set(3, "groupClassname");
		// 4: Inf-squad (8 man, AT/GL)
		mapSpawnTemplates.Set(4, "groupClassname");
		// 5: Inf-squad (4 man, AT)
		
		
		// Create an instance of the AISpawnHandler with defined templates
		iAISpawnHandler = new AISpawnHandler(mapSpawnTemplates);
		// Create an instance of the mission manager with the AISpawnHandler
		iMissionManager = new MissionManager(iAISpawnHandler);
		
		// Create an instance of mission phase
		MissionPhase missionPhase1 = new MissionPhase(1);
		
		// Add spawns to mission phase
		missionPhase1.AddCommand(new AISpawnGroup(1, "s_1", {"wp_1", "wp_2"}));
		
		
		// Add Mission Phase to the mission manager instance
		iMissionManager.AddMissionPhase(missionPhase1);
	}
}