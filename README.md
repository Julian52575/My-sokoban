# My-sokoban
Our first project with the [ncurses](https://en.wikipedia.org/wiki/Ncurses) librairy.   
We were asked to recode [sokoban](https://en.wikipedia.org/wiki/Sokoban).   
    
Compile the game with   
```make```    
and run it with   
```./my_sokoban [level.txt]```    
    
**P** is the player   
**X** are crates    
**O** are goals to put crates in    
**#** are walls   
    
I included a few levels inside the well named *levels*  folder, so try them !   
You can even create your own level as long as it only contains ' ', '#', 'X', 'O', 'P' and there is as much 'X' and 'O'
    
There is also the  *bonus*  folder with it own  *Makefile*  to compile a ~~buggy~~ **graphic** version of the game !    
It main purpose was to try to create a scrolling effect between differents screens. Please don't jugde it too hardly :)   
