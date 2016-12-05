import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class SudokuSolver {
	private ArrayList<Action> stack;
	private ArrayList<Action> temp;

	private int dimension;
	private int gridSize;
    private int mode;
	private int[][] sudoku;

	public SudokuSolver(int[][] data, int mode, int subgridSize) {
        this.sudoku    = data;
        this.mode      = mode;
        this.gridSize  = subgridSize;
        this.dimension = subgridSize*subgridSize;
	}

	public ArrayList<int[][]> findSolutions() {
		boolean flag = false;

		ArrayList<int[][]> solutions = new ArrayList<int[][]>();
		stack = new ArrayList<Action>();
		temp  = new ArrayList<Action>();

		do {
			if(isFinished()) {
				int[][] sol = new int[dimension][];
				for(int k=0; k<dimension; k++)
					sol[k] = sudoku[k].clone();

				solutions.add(sol);
				flag = false;
			} else {
				int[] coor;
				if((coor = findNext()) != null) {
					flag = populate(mode, coor);
				}
			}
			if(stack.isEmpty()) break;
			Action p = stack.remove(stack.size()-1);

			if(!flag) {
				Action p2;
				if(temp.isEmpty()) {
					p2 = null;
				} else {
					p2 = temp.get(temp.size()-1);
				}

				while(!temp.isEmpty() && (dimension*p2.r)+p2.c >= (dimension*p.r)+p.c) {
					p2 = temp.remove(temp.size()-1);

					sudoku[p2.r][p2.c] = 0;
					try {
						p2 = temp.get(temp.size()-1);
					} catch(ArrayIndexOutOfBoundsException e) {
						p2 = null;
					}
				}
			}

			temp.add(p);
			sudoku[p.r][p.c] = p.x;
		} while(true);

		return solutions;
	}

	public boolean isFinished() {
		for(int i=0; i<dimension; i++) {
			for(int j=0; j<dimension; j++) {
				if(sudoku[i][j] == 0) return false;
			}
		}
		return true;
	}

	public int[] findNext() {
		int[] coor = null;

		for(int i=0; i<dimension; i++) {
			for(int j=0; j<dimension; j++) {
				if(sudoku[i][j] == 0) {
					coor = new int[2];
					coor[0] = i;
					coor[1] = j;
					return coor;
				}
			}
		}

		return coor;
	}

	public boolean validateX() {
		Set<Integer> buffer = new HashSet<Integer>();
		int i, x;

		// Check X
		for(i=0; i<dimension; i++) {
			x = sudoku[i][i];
			if(x != 0 && buffer.contains(x))
				return false;
			buffer.add(x);
		}
		buffer.clear();

		for(i=0; i<dimension; i++) {
			x = sudoku[i][(dimension-1)-i];
			if(x != 0 && buffer.contains(x))
				return false;
			buffer.add(x);
		}
		buffer.clear();

		if(!validate()) return false;

		return true;
	}

	public boolean validateY() {
		Set<Integer> buffer = new HashSet<Integer>();
		int i, j, x;

		if(dimension % 2 != 0){
			// left wing
		    for(i=0; i<(dimension/2); i++){
		        for(j=0; j<dimension; j++){
		        	if((i == j && (j < (dimension/2))) || ((i == (dimension/2)) && (j >= (dimension/2)))){
		        		x = sudoku[i][j];
		        		if(x != 0 && buffer.contains(x))
		    				return false;
		    			buffer.add(x);
		        	}
		        }
		        buffer.clear();
		    }
		    // right wing
		    for(i=((dimension/2)+1); i<dimension; i++){
		        for(j=0; j<dimension; j++){
		        	if((j == (dimension-i-1) && (j < (dimension/2))) || ((i == (dimension/2)) && (j >= (dimension/2)))){
		        		x = sudoku[i][j];
		        		if(x != 0 && buffer.contains(x))
		    				return false;
		    			buffer.add(x);
		        	}
		        }
		        buffer.clear();
		    }
		} else return false;

		if(!validate()) return false;

		return true;
	}

	public boolean validateXY() {
		if(!validateX()) return false;
		if(!validateY()) return false;
		if(!validate())  return false;

		return true;
	}

	public boolean validate() {
		Set<Integer> buffer = new HashSet<Integer>();
		int i, j, k, l, x;

		// Check Rows
		for(i=0; i<dimension; i++) {
			for(j=0; j<dimension; j++) {
				x = sudoku[i][j];
				if(x != 0 && buffer.contains(x))
					return false;
				buffer.add(x);
			}
			buffer.clear();
		}

		// Check Columns
		for(i=0; i<dimension; i++) {
			for(j=0; j<dimension; j++) {
				x = sudoku[j][i];
				if(x != 0 && buffer.contains(x))
					return false;
				buffer.add(x);
			}
			buffer.clear();
		}

		// Check Grids
		for(i=0; i<dimension; i+=gridSize) {
			for(j=0; j<dimension; j+=gridSize) {
				for(k=i; k<(i+gridSize); k++) {
					for(l=j; l<(j+gridSize); l++) {
						x = sudoku[k][l];
						if(x != 0 && buffer.contains(x))
							return false;
						buffer.add(x);
					}
				}
				buffer.clear();
			}
		}

		return true;
	}

	public boolean populate(int type, int[] coor) {
		for(int i=dimension; i>0; i--) {
			sudoku[coor[0]][coor[1]] = i;
			switch(type) {
			case 0:
				if(validate()) {
					stack.add(new Action(i, coor[0], coor[1]));
				} else {
					sudoku[coor[0]][coor[1]] = 0;
				}
				break;
			case 1:
				if(validateX()) {
					stack.add(new Action(i, coor[0], coor[1]));
				} else {
					sudoku[coor[0]][coor[1]] = 0;
				}
				break;
			case 2:
				if(validateY()) {
					stack.add(new Action(i, coor[0], coor[1]));
				} else {
					sudoku[coor[0]][coor[1]] = 0;
				}
				break;
			case 3:
				if(validateXY()) {
					stack.add(new Action(i, coor[0], coor[1]));
				} else {
					sudoku[coor[0]][coor[1]] = 0;
				}
				break;
			}

		}

		return false;
	}

}
