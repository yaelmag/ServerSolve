cmake_minimum_required(VERSION 3.12.3)
project(project2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(project2 main.cpp Server.h MySerialServer.cpp MySerialServer.h
        ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h
        Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h
        TcpServer.cpp TcpServer.h ReverserSolver.cpp ReverserSolver.h Searcher.h BFS.h
        DFS.h Astar.h BestFirstSearch.h State.h Searchable.h MyClientHandler.cpp MyClientHandler.h MatrixSearchable.h Point.h Main.cpp SearcherSolver.h PriorityQueue.h MyParallelServer.cpp MyParallelServer.h)