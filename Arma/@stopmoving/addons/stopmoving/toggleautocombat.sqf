{ 
	for "_i" from 0 to count AIList do 
	{ 
		//if(_i != 0) then 
		//{
			if(_i == _x) then 
			{
				_a = AIList select _i;
			
				if(_a checkAIFeature "AutoCombat") then 
				{ 
					_a enableAIFeature ["AutoCombat", false] 
				}
				else 
				{
					_a enableAIFeature ["AutoCombat", true] 
				}
			}
		//}
	}
} forEach selectedUnitsList;