#include <iostream>
using namespace std;

#define N 4
#define INF 999

int main()
{
    int cost[N][N];
    int dist[N][N];
    int nextHop[N][N];

    cout << "Enter the cost matrix (use 999 for INF):\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }

    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = cost[i][j];

            if (i == j)
                nextHop[i][j] = i;

            else if (cost[i][j] != INF)
                nextHop[i][j] = j;

            else
                nextHop[i][j] = -1;
        }
    }

    
    int updated;

    do
    {
        updated = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    if (dist[i][k] != INF &&
                        dist[k][j] != INF &&
                        dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];

                        nextHop[i][j] = nextHop[i][k];

                        updated = 1;
                    }
                }
            }
        }

    } while (updated == 1);

    
    cout << "\nFinal Routing Tables\n";

    for (int i = 0; i < N; i++)
    {
        cout << "\nRouter R" << i + 1 << ":\n";
        cout << "Destination\tCost\tNext Hop\n";

        for (int j = 0; j < N; j++)
        {
            cout << "R" << j + 1 << "\t\t";

            if (dist[i][j] == INF)
                cout << "INF";
            else
                cout << dist[i][j];

            cout << "\t";

            if (nextHop[i][j] == -1)
                cout << "-";
            else
                cout << "R" << nextHop[i][j] + 1;

            cout << endl;
        }
    }

  
    int source, destination;

    cout << "\nEnter source router (1-4): ";
    cin >> source;

    cout << "Enter destination router (1-4): ";
    cin >> destination;

   
    source--;
    destination--;

    
    if (dist[source][destination] == INF)
    {
        cout << "\nNo path exists between the routers.\n";
        return 0;
    }

    
    cout << "\nShortest Distance: "
         << dist[source][destination] << endl;

   
    cout << "Shortest Path: ";

    int current = source;

    cout << "R" << current + 1;

    while (current != destination)
    {
        current = nextHop[current][destination];

        cout << " -> R" << current + 1;
    }

    cout << endl;

    return 0;
}