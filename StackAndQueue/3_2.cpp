#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class Queue
{
private:
    T *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int cap = 100)
    {
        capacity = cap;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(T value)
    {
        if (isFull())
        {
            std::cout << "Queue is full!\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!\n";
            return T();
        }
        T value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }
};

struct Point
{
    int x, y;
};

void findPathInMaze(int **maze, int N, int M, Point start, Point end)
{
    if (maze[start.x][start.y] == 1 || maze[end.x][end.y] == 1)
    {
        std::cout << "No path exists (start or end is blocked)!\n";
        return;
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    Queue<Point> q;
    bool visited[100][100] = {false};
    Point parent[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            parent[i][j] = {-1, -1};
        }
    }

    q.enqueue(start);
    visited[start.x][start.y] = true;

    bool found = false;
    while (!q.isEmpty())
    {
        Point current = q.dequeue();

        if (current.x == end.x && current.y == end.y)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && !visited[newX][newY] && maze[newX][newY] == 0)
            {
                q.enqueue({newX, newY});
                visited[newX][newY] = true;
                parent[newX][newY] = current;
            }
        }
    }

    if (!found)
    {
        std::cout << "No path exists!\n";
        return;
    }

    Point path[1000];
    int pathLength = 0;
    Point current = end;
    while (current.x != -1 && current.y != -1)
    {
        path[pathLength++] = current;
        current = parent[current.x][current.y];
    }

    std::cout << "Path from (" << start.x << "," << start.y << ") to (" << end.x << "," << end.y << "):\n";
    for (int i = pathLength - 1; i >= 0; i--)
    {
        std::cout << "(" << path[i].x << "," << path[i].y << ")";
        if (i > 0)
            std::cout << " -> ";
    }
    std::cout << "\n";
}

void findPathInGrid(int grid[5][5], int N, int M)
{
    Point start = {-1, -1}, end = {-1, -1};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 2)
                start = {i, j};
            if (grid[i][j] == 6)
                end = {i, j};
        }
    }

    if (start.x == -1 || end.x == -1)
    {
        std::cout << "Start or end point not found!\n";
        return;
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    Queue<Point> q;
    bool visited[5][5] = {false};
    Point parent[5][5];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            parent[i][j] = {-1, -1};
        }
    }

    q.enqueue(start);
    visited[start.x][start.y] = true;

    bool found = false;
    while (!q.isEmpty())
    {
        Point current = q.dequeue();

        if (current.x == end.x && current.y == end.y)
        {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && !visited[newX][newY] && grid[newX][newY] != 1)
            {
                q.enqueue({newX, newY});
                visited[newX][newY] = true;
                parent[newX][newY] = current;
            }
        }
    }

    if (!found)
    {
        std::cout << "No path exists!\n";
        return;
    }

    Point path[100];
    int pathLength = 0;
    Point current = end;
    while (current.x != -1 && current.y != -1)
    {
        path[pathLength++] = current;
        current = parent[current.x][current.y];
    }

    std::cout << "Path from (" << start.x << "," << start.y << ") to (" << end.x << "," << end.y << "):\n";
    for (int i = pathLength - 1; i >= 0; i--)
    {
        std::cout << "(" << path[i].x << "," << path[i].y << ")";
        if (i > 0)
            std::cout << " -> ";
    }
    std::cout << "\n";
}

int main()
{
    std::cout << "Testing Maze (BFS with Queue)\n";
    std::ifstream mazeFile("maze.txt");
    if (!mazeFile)
    {
        std::cout << "Cannot open maze.txt!\n";
        return 1;
    }

    int N, M;
    mazeFile >> N >> M;
    int **maze = new int *[N];
    for (int i = 0; i < N; i++)
    {
        maze[i] = new int[M];
        for (int j = 0; j < M; j++)
        {
            mazeFile >> maze[i][j];
        }
    }

    Point start, end;
    mazeFile >> start.x >> start.y >> end.x >> end.y;
    mazeFile.close();

    findPathInMaze(maze, N, M, start, end);

    for (int i = 0; i < N; i++)
    {
        delete[] maze[i];
    }
    delete[] maze;

    std::cout << "\nTesting Grid Path (BFS with Queue)\n";
    std::ifstream gridFile("grid.txt");
    if (!gridFile)
    {
        std::cout << "Cannot open grid.txt!\n";
        return 1;
    }

    int grid[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            gridFile >> grid[i][j];
        }
    }
    gridFile.close();

    findPathInGrid(grid, 5, 5);

    return 0;
}