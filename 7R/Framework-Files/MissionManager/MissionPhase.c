class MissionPhase
{
	// Internal variables
	private int _phaseNumber;
	private array<AISpawnCommandBase> _missionPhaseCommands;
	
	// Constructor
	void MissionPhase(int phaseNumber)
	{
		_phaseNumber = phaseNumber;
		Print("[Mission Phase] Mission Phase constructed", LogLevel.DEBUG);
	}
	
	// Destructor
	void ~MissionPhase()
	{
		Print("[Mission Phase] Mission Phase deconstructed", LogLevel.DEBUG);
	}
	
	// Properties
	int GetPhaseNumber()
	{
		return _phaseNumber;
	}
	
	// Add commands to command array
	void AddCommand(AISpawnCommandBase aiSpawnCommand)
	{
		if (!aiSpawnCommand)
		{
			Print("[Mission Phase] Mission Phase" + _phaseNumber + "Command added failed for", LogLevel.ERROR);
			return;
		}
		
		_missionPhaseCommands.Insert(aiSpawnCommand);
	}
	
	// Execute Mission Phase
	void Execute(AISpawnHandler aiSpawnHandler)
	{
		Print("[Mission Phase] Executing mission phase " + _phaseNumber, LogLevel.DEBUG);
		
		if (_missionPhaseCommands.IsEmpty())
		{
			Print("[Mission Phase] Mission Phase" + _phaseNumber + " Commands is empty", LogLevel.ERROR);
			return;
		}
		
		// Loop through AIspawner commands
		foreach (AISpawnCommandBase missionPhaseCommand : _missionPhaseCommands)
		{
			if (!missionPhaseCommand)
			{
				Print("[Mission Phase] Mission Phase" + missionPhaseCommand + " is empty", LogLevel.ERROR);
			}
			
			missionPhaseCommand.Execute(aiSpawnHandler)
		}
	}
}