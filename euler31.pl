:- module(euler30, [combination/2, wrapper/2, takeList/1]).
:- [coins].

wrapper(Wanted,Result) :- combination(Wanted,Result), isDescending(Result).

combination(0,[]).
combination(Wanted,[C1|Tail]) :- Wanted > 0,addCoin(H,C1), Left is Wanted-C1, combination(Left,Tail).

addCoin(Coin,Money) :- coin(Coin,Money).

isDescending([]).
isDescending([H|T]) :-  headOf(T,H1), H>=H1, isDescending(T).

headOf([],0). 
headOf([H1|_],H1).

