{ 
	for "_i" from 0 to count AIList do 
	{ 
		//if(_i != 0) then 
		//{
			if(_i == _x) then 
			{
				_a = AIList select _i;
			
				if(_a checkAIFeature "PATH") then 
				{ 
					_a enableAIFeature ["PATH", false] 
				}
				else 
				{
					_a enableAIFeature ["PATH", true] 
				}
			}
		//}
	}
} forEach selectedUnitsList;