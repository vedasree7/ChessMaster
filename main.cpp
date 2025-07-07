#include "ChessSolver.hpp"
#include "ClosestSolver.hpp"

/**
 * Command-driven interface to interact with the ChessSolver and ClosestSolver.
 */
int main() {
    ChessSolver chessBoard;
    string command;

    while (cin >> command) {
        if (command == "CREATE_2D") {
            int size;
            cin >> size;
            chessBoard = ChessSolver(size);
        } 
        else if (command == "SORT_2D") {
            string orderType;
            cin >> orderType;
            chessBoard.sortRows(orderType == "descending");
        } 
        else if (command == "INVERSION_2D") {
            cout << chessBoard.countInversions() << endl;
        } 
        else if (command == "DISPLAY_2D") {
            chessBoard.display();
        } 
        else if (command == "CLOSEST_2D") {
            int numPoints;
            cin >> numPoints;
            vector<pair<long long, long long>> points(numPoints);
            for (auto &point : points)
                cin >> point.first >> point.second;

            ClosestSolver solver(points);
            solver.solveAndPrint();
        } 
        else if (command == "END") {
            break;
        }
    }
}
