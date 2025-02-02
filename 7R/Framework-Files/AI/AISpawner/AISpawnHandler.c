class AISpawnHandler
{
	// Internal variables
	private ref map<int, string> mSpawnTemplates
	
	// Constructor
	void AISpawnHandler(map<int, string> spawnTemplates)
	{
		if (!spawnTemplates)
		{
			Print("[AI Spawnhandler] Invalid mapSpawnTemplates given", LogLevel.ERROR);
		}
		
		// Might need to add a copy()
		mSpawnTemplates = spawnTemplates;
		
		Print("[AI Spawnhandler] AI Spawnhandler constructed", LogLevel.DEBUG);
	}
	
	// Destructor
	void ~AISpawnHandler()
	{
		Print("[AI Spawnhandler] AI Spawnhandler deconstructed", LogLevel.DEBUG);
	}
	
	// Properties
	// Get Template based on ID
	string GetAISpawnTemplate(int key)
	{
		return  mSpawnTemplates.Get(key);
	}

	// Public functions
	// Generate and validate resource
	Resource GenerateAndValidateResource(string resourceToLoad)
	{
		// Load the resource
		Resource resource = Resource.Load(resourceToLoad);
		
		// Validate the prefab and show an appropriate error if invalid
		if(!resource.IsValid())
		{
			Print(("[AI Spawnhandler: Generate And Validate Resource] Resource is invalid: " + resourceToLoad), LogLevel.ERROR);
			return null;
		}
		
		// Return the resource
		return resource;
	}
	
	// Generates spawn parameters for any entity
	EntitySpawnParams GenerateSpawnParameters(vector spawnPosition)
	{
		// Create a new set of spawn parameters
		EntitySpawnParams params = EntitySpawnParams();
		params.TransformMode = ETransformMode.WORLD;
		
		// Assign the postion to those parameters
		params.Transform[3] = spawnPosition;
		
		// Return this set of spawn parameters
		return params;
	}
	
	// Create waypoints
	AIWaypoint CreateWayPoint(string waypointName)
	{
		// Find waypoint entity
		IEntity waypointEntity = GetGame().GetWorld().FindEntityByName(waypointName);
		
		if (!waypointEntity) {
			Print(("[AI Spawnhandler: Create WayPoint] Waypoint does not exist: " + waypointName), LogLevel.ERROR);
			return null;
		}
		
		// Get Type of waypoint entity
		string waypointType = waypointEntity.Type().ToString();
		// Get position of waypoint entity
		vector waypointPosition = waypointEntity.GetOrigin();

		// Generate the resource
		Resource resource = GenerateAndValidateResource(waypointType);
		
		if (!resource)
		{
			Print(("[AI Spawner: Create WayPoint] Unable to load resource for the waypoint: " + waypointType), LogLevel.ERROR);
			return null;
		}
		
		// Generate the spawn parameters and create the waypoint
		AIWaypoint waypoint = AIWaypoint.Cast(GetGame().SpawnEntityPrefab(resource, null, GenerateSpawnParameters(waypointPosition)));
		
		if (!waypoint)
		{
			Print("[AI Spawner: Create WayPoint] Unable to create waypoint!", LogLevel.ERROR);
			return null;
		}
		
		return waypoint;
	}
	
	
}