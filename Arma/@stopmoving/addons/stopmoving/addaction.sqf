//not used anymore

player addAction ["Open Dialog", {execVM "\stopmoving\openDialog.sqf"}];

for "_i" from 0 to count units player do    
{     
	if(_i != 0) then 
	{ 
		player removeAction _i; 
	}  
}