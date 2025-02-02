class SCR_7R_Platoon
{
	// Internal variables
	private bool _platoonsquad = false;
	private bool _squads[4] = {false, false, false, false};
	private bool _echosquads[2] = {false, false};
	private bool _sierrasquads[2] = {false, false};
	private bool _foxtrotsquads[2] = {false, false};
	private bool _mikesquads[4] = {false, false, false, false};
	private bool _rodeosquads[4] = {false, false, false, false};
	private bool _whiskeysquads[2] = {false, false};
	
	// Constructor
	void SCR_7R_Platoon(bool platoonsquad = true, int squads = 4, int echos = 0, int sierras = 0, int foxtrots = 0, int mikes = 0, int rodeos = 0, int whiskeys = 0)
	{
		// Add platoon squad
		if (platoonsquad) {_platoonsquad = true};
		for (int i = 0; i < squads; i++) { _squads[i] = true; }
		
		// Add squads
		if (echos > 2) {echos = 2};
		for (int i = 0; i < echos; i++) { _echosquads[i] = true; }
		
		// Add sierras
		if (sierras > 2) {sierras = 2};
		for (int i = 0; i < sierras; i++) { _sierrasquads[i] = true; }
		
		// Add foxtrots
		if (foxtrots > 2) {foxtrots = 2};
		for (int i = 0; i < foxtrots; i++) { _foxtrotsquads[i] = true; }
		
		// Add mikes
		if (mikes > 2) {mikes = 4};
		for (int i = 0; i < mikes; i++) { _mikesquads[i] = true; }
		
		// Add rodeos
		if (rodeos > 2) {rodeos = 4};
		for (int i = 0; i < rodeos; i++) { _rodeosquads[i] = true; }
		
		// Add whiskeys
		if (whiskeys > 2) {whiskeys = 2};
		for (int i = 0; i < whiskeys; i++) { _whiskeysquads[i] = true; }
		
	}
	
	// Destructor
	void ~SCR_7R_Platoon()
	{
	}
	
	
}