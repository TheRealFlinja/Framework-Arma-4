class AITemplate
{
	// class might exist already (Check later)
	// Internal variables
	private string _groupLeader
	private array<string> _groupMembers
	
	// Constructor
	void AITemplate(string groupLeader, array<string> groupMembers)
	{
		this._groupLeader = groupLeader;
		this._groupMembers = groupMembers;
		
		Print("[AI Template] AI Template constructed", LogLevel.DEBUG);
	}
	
	// Destructor
	void ~AITemplate()
	{
		Print("[AI Template] AI Template deconstructed", LogLevel.DEBUG);
	}
	
	// Properties
	string GetGroupLeader()
	{
		return this._groupLeader;
	}
	
	array<string> GetGroupMembers()
	{
		// check if needs .copy()
		return this._groupMembers;
	}
}