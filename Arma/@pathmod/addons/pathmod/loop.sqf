hint "loop started";

theguys = [];

while{true} do 
{
	{
		if((side _x) == west) then 
		{
			if(_x != player) then 
			{
				if(alive _x or _x isEqualTo objNull) then
				{
					if!(_x in theguys) then 
					{
						_x disableAI "AUTOCOMBAT";
						_x disableAI "SUPPRESSION";
						//_x disableAI "COVER";
						
						_x allowFleeing 0;
					
						theguys pushBack _x;
						//systemChat format ["Added = %1", _x];
						//systemChat format ["theguys size = %1", count theguys];
					}
				};
			};
		};
	} forEach allUnits;

	if(count theguys >= 1) then 
	{
		{
			if(!alive _x or _x isEqualTo objNull) then
			{
				theguys deleteAt count units group _x;
			};
		
			if(count units group _x > 1 && leader _x != player && isNull objectParent _x == true) then 
			//if(leader _x != player) then 
			{
				if(isFormationLeader _x) then 
				{
					_expectedDestination = expectedDestination _x select 0; 
					_expectedDestination_x = _expectedDestination select 0; 
					_expectedDestination_y = _expectedDestination select 1; 
					_expectedDestination_z = _expectedDestination select 2;
					
					_NotReady = true;
					
					if(getPosATL _x select 0 >= (_expectedDestination_x) - 1) then
					{
						if(getPosATL _x select 0 <= (_expectedDestination_x) + 1) then
						{
							if(getPosATL _x select 1 >= (_expectedDestination_y) - 1) then
							{
								if(getPosATL _x select 1 <= (_expectedDestination_y) + 1) then
								{
									if(getPosATL _x select 2 >= (_expectedDestination_z) - 1) then
									{
										if(getPosATL _x select 2 <= (_expectedDestination_z) + 1) then
										{
											_NotReady = false;
										};
									};
								};
							};
						};
					};
					
					if(_NotReady) then 
					{
						_x enableAI "PATH";
						_x enableAI "TARGET";
					}
					else
					{
						_x disableAI "PATH";
						_x disableAI "TARGET";
					};
				}
				else
				{
					_SubNotReady = true;
					
					if(getPosATL _x select 0 >= (formationPosition _x select 0) - 1) then
					{
						if(getPosATL _x select 0 <= (formationPosition _x select 0) + 1) then
						{
							if(getPosATL _x select 1 >= (formationPosition _x select 1) - 1) then
							{
								if(getPosATL _x select 1 <= (formationPosition _x select 1) + 1) then
								{
									if(getPosATL _x select 2 >= (formationPosition _x select 2) - 1) then
									{
										if(getPosATL _x select 2 <= (formationPosition _x select 2) + 1) then
										{
											_SubNotReady = false;
										};
									};
								};
							};
						};
					};
					
					if(_SubNotReady) then 
					{
						_x enableAI "PATH";
						_x enableAI "TARGET";
					}
					else
					{
						_x disableAI "PATH";
						_x disableAI "TARGET";
					};
				};
			}
			else
			{
				_expectedDestination = expectedDestination _x select 0; 
				_expectedDestination_x = _expectedDestination select 0; 
				_expectedDestination_y = _expectedDestination select 1; 
				_expectedDestination_z = _expectedDestination select 2;
				
				_NotReady = true;
				
				if(isNull objectParent _x == true) then
				{
					if(getPosATL _x select 0 >= (_expectedDestination_x) - 1) then
					{
						if(getPosATL _x select 0 <= (_expectedDestination_x) + 1) then
						{
							if(getPosATL _x select 1 >= (_expectedDestination_y) - 1) then
							{
								if(getPosATL _x select 1 <= (_expectedDestination_y) + 1) then
								{
									if(getPosATL _x select 2 >= (_expectedDestination_z) - 1) then
									{
										if(getPosATL _x select 2 <= (_expectedDestination_z) + 1) then
										{
											_NotReady = false;
										};
									};
								};
							};
						};
					};
				}
				else
				{
					if(unitReady _x) then
					{
						_NotReady = false;
					};
				};
				
				if(_NotReady) then 
				{
					_x enableAI "PATH";
					_x enableAI "TARGET";
				}
				else
				{
					_x disableAI "PATH";
					_x disableAI "TARGET";
				};
			};
		} forEach theguys;
	};
};

//AI can by them self be unitReady = false
//AI group memebers cannot move, only team leader