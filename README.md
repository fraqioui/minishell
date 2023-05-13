# MINISHELL
`minishell` this project is about creating your own shell with the rules imposed in the subject (look for the subject between repo files).
//example of the work

> PS: In advance, I wanted to tell that I invested lots of time and energy on this project to make it easy for you to work on since I was 
> too confused when I started it, I didn't know what to do or from where to start. I've read a lot of articles and went from all the resources 
> that old students suggests in their articles, But always those articles weren't enough for me to have this general picture about the project.
> Thus, I've decided to work on this project on my own besides knowing that it would consume a lot of blackhole days, but that was okay 
> for me knowing that I would get out with a general picture of the project. So the people working on the project and the next promos wouldn't 
> suffer from this, and instead of wasting time thinking about where to start, they would have enough to be creative and invent new ideas
> I would be proud of them. This project is not perfect and I am totally aware of this, but I am sure it's gonna be a good starting point
> Hope it is going to inspire you. You should not do none of the ideas if they didn't fit you but they just an inspiration.

Contents
========

 * [0. Algorithm/pseudocode](#Algorithm/pseudocode)
 * [1. Initializing](#Initializing)
 * [2. Parsing](#2.Parsing)
 * [2.1. Parser](#2.1.Parser)
 * [2.2. Tokenizer](#2.2.Tokenizer)
 * [2.3. Re-order command](#2.3.Re-order-command)
 * [2.4. Build the tree](#2.4.Build-the-tree)
 * [3. Executing](#3.Executing)
 * [3.1. Builtins](#3.1.Builtins)
 * [3.2. Executor](#3.2.Executor)
 * [3.2.1. and/or](#3.2.1.and/or)
 * [3.2.2. pipes](#3.2.2.pipes)
 * [3.2.3. redirections](#3.2.3redirections)
 * [3.2.4. command](#3.2.4.command)
 * [3.2.4.1. Expanding](#3.2.4.1.Expanding)
 * [3.2.4.2. Wildcard *](#3.2.4.2.Wildcard)
 * [3.2.4.3. executing the command after forking](#3.2.4.3.execution)
 * [4. Resources](#4.Resources)

### Algorithm/pseudocode
---

1. Initializing: 
      - The elements of the struct that is global: The status code + The environment variables. 
      - Saving stander input / stander output using dup. [man dup](https://man7.org/linux/man-pages/man2/dup.2.html)
      - Reading user input command using readline function. [man readline](https://linux.die.net/man/3/readline)
2. Parsing:
      - Building a doubly linked list that holds the command specifying it into tokens using [shell grammar](https://cs61.seas.harvard.edu/site/2019/Section7/).
      - While tokenizing the command I check for syntax errors.
      - Then I re-order the cmd using [Shunting yard algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm) that made it easy for me to build the tree recursively.
      - Building the tree.
3. Executing:
      - Executing the tree recursively bottom-up & from left to right.
      - If the token is and/or/pipe. (This would be explained later)
      - else, the token would be a command. 1. expand $ 2. split the cmd by spaces out of quotes
        -- 3. expand wildcard 4. eliminate main quotes 5. handle redirections 4. check if the cmd is a builtin 
        -- 5. if it is not a builtin, I fork and then execute the cmd using execve.

###Initializing
---
Put the environment variables into a linked list so you can delete or add to them later using export and unset builtins.
In addition to display them using env or export (without arguments) builtins.
![](env.png)



































