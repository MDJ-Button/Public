{ 
	if(_x checkAIFeature "PATH") then 
	{ 
		_x enableAIFeature ["PATH", false] 
	}
	else 
	{
		_x enableAIFeature ["PATH", true] 
	}

} forEach groupSelectedUnits player;