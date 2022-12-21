{
	lbSetColor [1500, _x, [255, 255, 255, 1]];
} forEach SongList;
playMusic "";

lbSetColor [1500, lbCurSel 1500, [255, 165, 0, 0.5]];
_i = subclasses select lbCurSel 1500;
playMusic _i;
