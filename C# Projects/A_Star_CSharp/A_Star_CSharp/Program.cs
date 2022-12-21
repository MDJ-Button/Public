using System;
using System.Collections.Generic;

namespace A_Star_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
			List<string> map = new List<string>
			{
				"A          ",
				"--| |------",
				"           ",
				"   |-----| ",
				"   |     | ",
				"---|     |B"
			};

			var start = new Tile();
			start.Y = map.FindIndex(x => x.Contains("A"));
			start.X = map[start.Y].IndexOf("A");

			var finish = new Tile();
			finish.Y = map.FindIndex(x => x.Contains("B"));
			finish.X = map[finish.Y].IndexOf("B");

			start.SetDistance(finish.X, finish.Y);

			var activeTiles = new List<Tile>();
			activeTiles.Add(start);
			var visitedTiles = new List<Tile>();
		}
    }

	class Tile
	{
		public int X { get; set; }
		public int Y { get; set; }
		public int Cost { get; set; }
		public int Distance { get; set; }
		public int CostDistance => Cost + Distance;
		public Tile Parent { get; set; }

		//The distance is essentially the estimated distance, ignoring walls to our target. 
		//So how many tiles left and right, up and down, ignoring walls, to get there. 
		public void SetDistance(int targetX, int targetY)
		{
			this.Distance = Math.Abs(targetX - X) + Math.Abs(targetY - Y);
		}
	}

	private static List<Tile> GetWalkableTiles(List<string> map, Tile currentTile, Tile targetTile)
	{
		var possibleTiles = new List<Tile>()
	{
		new Tile { X = currentTile.X, Y = currentTile.Y - 1, Parent = currentTile, Cost = currentTile.Cost + 1 },
		new Tile { X = currentTile.X, Y = currentTile.Y + 1, Parent = currentTile, Cost = currentTile.Cost + 1},
		new Tile { X = currentTile.X - 1, Y = currentTile.Y, Parent = currentTile, Cost = currentTile.Cost + 1 },
		new Tile { X = currentTile.X + 1, Y = currentTile.Y, Parent = currentTile, Cost = currentTile.Cost + 1 },
	};

		possibleTiles.ForEach(tile => tile.SetDistance(targetTile.X, targetTile.Y));

		var maxX = map.First().Length - 1;
		var maxY = map.Count - 1;

		return possibleTiles
				.Where(tile => tile.X >= 0 && tile.X <= maxX)
				.Where(tile => tile.Y >= 0 && tile.Y <= maxY)
				.Where(tile => map[tile.Y][tile.X] == ' ' || map[tile.Y][tile.X] == 'B')
				.ToList();
	}
}
