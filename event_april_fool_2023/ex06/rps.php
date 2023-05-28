<?php

// get user's choice
$user_choice = strtolower(readline("Choose rock, paper, or scissors: "));

// generate computer's choice
$computer_choice = array("rock", "paper", "scissors")[rand(0,2)];

// detect wrong entries
if (in_array($user_choice, array("rock", "paper", "scissors")) == False)
{
	echo "You need to select either rock, paper or scissors !\n";
	exit(1);
}
// determine winner
if ($user_choice == $computer_choice)
{
    echo "It's a tie!\n";
}
elseif ($user_choice == "rock" && $computer_choice == "scissors" ||
          $user_choice == "paper" && $computer_choice == "rock" ||
          $user_choice == "scissors" && $computer_choice == "paper")
{
    echo "Congratulations! You won! The computer chose $computer_choice.\n";
}
else
{
    echo "Sorry, you lost. The computer chose $computer_choice.\n";
}

?>
