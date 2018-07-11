
class Game:
    def __init__(self):
        self.board = Board(6, 7)
        self.player = [None, None]
        self.make_player()

    def make_player(self):
        for i in range(2):
            p_cls = self.select_type(i)
            self.player[i] = p_cls(i)
        self.p_dict = {self.player[0]: self.player[1],
                       self.player[1]: self.player[0]}
        self.cur_p = self.player[0]

    def select_type(self, i):
        type_list = {0: Human, 1: AI}
        print('player{}のタイプを選択してください'.format(i))
        print('0: Human, 1: AI')
        t = int(input())
        return type_list[t]

    def play(self):
        board = self.board
        while not board.is_end():
            x, y = self.cur_p.select(board)
            board.put_stone(x, y, self.cur_p.color)
            self.change_player()
        self.show_result()

    def change_player(self):
        self.cur_p = self.p_dict[self.cur_p]

    def show_result(self):
        pass




class Board:
    def __init__(self, w, h):
        self.WIDTH = w
        self.HEIGHT = h
        self.grid = [[0 for i in range(w)] for j in range(h)]

    def put_stone(self, x, y, color):
        self.grid[x][y] = color

    def is_end(self):
        return True



class Player:
    def __init__(self, color):
        self.color = color

    def select(self, board):
        pass

class Human(Player):
    def select(self, board):
        # 手の入力を受け付ける
        return 0, 0

class AI(Player):
    def select(self, board):
        # 手を選ぶ
        return 0, 0



Game().play()
