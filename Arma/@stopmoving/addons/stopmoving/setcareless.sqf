{ 
	for "_i" from 0 to count AIList do 
	{ 
		//if(_i != 0) then 
		//{
			if(_i == _x) then 
			{
				_a = AIList select _i;
			
				_a setBehaviour "CARELESS";
			}
		//}
	}
} forEach selectedUnitsList;