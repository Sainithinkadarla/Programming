import random

def print_board(board):
    for row in board:
        for cell in row:
            print(cell, end=' ')
        print()

def make_move(board, player, position):
    board[position // 3][position % 3] = player

def check_win(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True

    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True

    if all(board[i][i] == player for i in range(3)):
        return True

    if all(board[i][2 - i] == player for i in range(3)):
        return True

    return False

def is_game_over(board):
    for row in board:
        for cell in row:
            if cell == '-':
                return False

    return True or check_win(board, 'X') or check_win(board, 'O')

def user_move(board):
    while True:
        try:
            position = int(input("Enter your move (1-9): ")) - 1
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 9.")
            continue

        if position < 0 or position > 8:
            print("Invalid position. Please enter a number between 1 and 9.")
            continue

        if board[position // 3][position % 3] != '-':
            print("Position already taken. Please choose another position.")
            continue

        break

    make_move(board, 'X', position)

def system_move(board):
    available_positions = []
    for row in range(3):
        for col in range(3):
            if board[row][col] == '-':
                available_positions.append(row * 3 + col)

    position = random.choice(available_positions)
    make_move(board, 'O', position)

def play_game():
    board = [['-', '-', '-'],
              ['-', '-', '-'],
              ['-', '-', '-']]

    current_player = 'X'

    while True:
        print_board(board)

        if current_player == 'X':
            user_move(board)
        else:
            system_move(board)

        if check_win(board, current_player):
            print_board(board)
            print(f"{current_player} wins!")
            break

        if is_game_over(board):
            print_board(board)
            print("It's a tie!")
            break

        current_player = 'O' if current_player == 'X' else 'X'

play_game()