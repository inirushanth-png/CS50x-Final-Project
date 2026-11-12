from cs50 import get_float

while True:
    change = get_float("Change: ")
    if 0<= change:
      break

cents = round(change*100)


quarters = (cents)//(25)
balance = cents % 25

dimes = (balance)//(10)
dimesbalance = balance % 10

nickels = (dimesbalance)//(5)
nickbalance = dimesbalance % 5

pennies = (nickbalance)//1
last = nickbalance % 1

total_coins = quarters + dimes + nickels +pennies
print(total_coins)


