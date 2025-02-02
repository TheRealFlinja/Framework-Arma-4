class MissionManager
{
	// Internal variables (Components)
	private ref AISpawnHandler _aiSpawner;
	private ref map<int, MissionPhase> _missionPhases = new map<int, MissionPhase>();
	
	// Constructor
	void MissionManager(AISpawnHandler aiSpawner)
	{
		if (!aiSpawner)
		{
			Print("[Mission Manager] Invalid aiSpawner given", LogLevel.ERROR);
		}
		
		_aiSpawner = aiSpawner;
		
		Print("[Mission Manager] Mission manager constructed", LogLevel.DEBUG);
	}
	
	// Destructor
	void ~MissionManager()
	{
		Print("[Mission Manager] Mission manager deconstructed", LogLevel.DEBUG);
	}
	
	// Add mission phase
	void AddMissionPhase(MissionPhase missionPhase)
	{
		if (_missionPhases.Contains(missionPhase.GetPhaseNumber()))
		{
			Print("[Mission Manager] Mission phase key already exists: " + missionPhase.GetPhaseNumber(), LogLevel.WARNING);
			return;
		}
		
		_missionPhases.Set(missionPhase.GetPhaseNumber(), missionPhase);
	}
	
	void ExecuteMissionPhase(int phaseNumber)
	{
		_missionPhases.Get(phaseNumber).Execute(_aiSpawner);
	}
}