IN PROGRESS

This project arose from doing challenges on Project Euler (http://projecteuler.net/) and the fact
where the numbers that you end up using in the midst of these challenges just get too big for an integer.

The goal is to create a BigInt class that would be used in place of a standard integer for these challenges
that use extremely large numbers. This BigInt could potentially (hopefully) be an unlimited size but in actuality
would be constrained by how much memory you have as it would need to be stored in memory somehow.

My first idea was to store a number as a string, as strings are not constrained by the same sizes as integers.