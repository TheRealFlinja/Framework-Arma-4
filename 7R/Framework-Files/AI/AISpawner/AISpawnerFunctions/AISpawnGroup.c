class AISpawnGroup: AISpawnCommandBase
{
	// Internal variables
	private int  _templateID;
	private string _spawnPointName;
	private vector _spawnPointPosition;
	private array<string> _pathWaypointNames;
	
	private bool _vehicle;
	
	// Constructor
	void AISpawnGroup(int templateID, string spawnPointName, array<string> pathWaypointNames)
	{
		// Set internal variables
		this._templateID = templateID;
		this._spawnPointName = spawnPointName;
		this._pathWaypointNames = pathWaypointNames;
	}
	
	void ~AISpawnGroup()
	{
	}
	
	override void Execute(AISpawnHandler aiSpawnHandler)
	{
		// Generate template
		Resource resource = aiSpawnHandler.GenerateAndValidateResource(aiSpawnHandler.GetAISpawnTemplate(_templateID));
		
		if (!resource)
		{
			Print(("[AI Spawn Group] Unable to load resource for template with ID " + _templateID), LogLevel.ERROR);
			return;
		}
		
		// Spawn group
			// Find waypoint
			IEntity spawnPoint = GetGame().GetWorld().FindEntityByName(_spawnPointName);
			//Generate spawn parameters and spawn group
			SCR_AIGroup group = SCR_AIGroup.Cast(GetGame().SpawnEntityPrefab(resource, null, aiSpawnHandler.GenerateSpawnParameters(spawnPoint.GetOrigin())));
		
			if (!group)
			{
				Print("[AI Spawn Group] Unable to spawn group!", LogLevel.ERROR);
				return;
			}
		
		// Create AI pathing
		foreach(string waypointName : _pathWaypointNames)
		{
			// Create waypoint
			AIWaypoint waypoint = aiSpawnHandler.CreateWayPoint(waypointName);
			
			if (!waypoint)
			{
				Print("[AI Spawn Group] Unable to add waypoint: " + waypointName, LogLevel.ERROR);
				return;
			}
			
			// Assign waypoint to group
			group.AddWaypoint(waypoint)
		}
	}
}