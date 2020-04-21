# multiproc
##我学到了什么
1. c语言命令行的基本使用
2. fork的原理及使用
    1. fork两个返回值，父进程返回进程号，子进程返回0
    2. 参考https://blog.csdn.net/kwinway/article/details/79633285，for循环中fork可能孩子生孙子，如何达到自己想要的效果
3. read，open，close等系统调用的使用
    1. 文件标识符
    2. 各个进程通过同一个文件描述符，得到open file table，进而得到inode，进行互相协作。
    3. 此次作业中的关键点
        1. fork前open文件，则父子进程共享一个文件描述信息，只需close一次即可
        2. fork后open文件，父子进程都是从开始处读取，没有共享信息
4.  sigaction，waitpid来避免僵尸进程
     1. 僵尸进程：   假设子进程结束时父进程仍存在，而父进程fork() 之前既没安装SIGCHLD信号处理函数调用wait()或waitpid()等待子进程结束， 又没有显式忽略该信号，则子进程成为僵尸进程，无法正常结束。 
        1. 如果父进程很忙，那么可以用signal函数为SIGCHLD安装handler，因为子 进程结束后， 父进程会收到该信号，可以在handler中调用wait搜索回收。 
        2. 如果父进程不关心子进程什么时候结束， 那么可以用signal （SIGCHLD,SIG_IGN） 通知内核，自己对子进程的结束不感兴趣，那么 子进程结束后，内核会回收， 并不再给父进程发送信号。
     2. waitpid()函数  pid / options  提供了额外选项来控制waitpid，如WNOHANG，说明若pid指定的子进程没有结束，则 waitpid()函数返回0，不予以等待。若结束，则返回该子进程的ID。  waitpid()只有在处理完所有终止进程后才返回 
     3. sigaction，参考了https://blog.csdn.net/weibo1230123/article/details/81411827