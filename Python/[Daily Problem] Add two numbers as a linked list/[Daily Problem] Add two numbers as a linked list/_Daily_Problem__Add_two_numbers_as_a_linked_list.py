# Definition for singly-linked list.
class ListNode(object):
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution:
  def addTwoNumbers(self, l1, l2, c = 0):

    temp_l1 = [];
    temp_l2 = [];
    temp_l3 = [];

    # Add linked list l1 & l2 to lists temp_l1 & temp_l2
    while l1:
        temp_l1.append(l1.val);
        l1 = l1.next;

    while l2:
        temp_l2.append(l2.val);
        l2 = l2.next;

    # Convert temp_l1 & temp_l2 to strings then to integers x and y
    strings = [str(integer) for integer in temp_l1]
    a_string = "". join(strings)
    x = int(a_string)

    strings = [str(integer) for integer in temp_l2]
    a_string = "". join(strings)
    y = int(a_string)

    # Count x and y together then convert the combine_int to a string
    combine_int = x + y;
    combine_str = str(combine_int);

    # Loop the combine_str and add each character to temp_l3
    for char in combine_str:
        temp_l3.append(int(char));

    # Reverse temp_l3 to get the value of 708 because
    # 243 + 564 = 807
    # 342 + 465 = 807
    temp_l3.reverse();

    # Create linked list with temp_l3
    l3 = ListNode(temp_l3[0]);
    l3.next = ListNode(temp_l3[1]);
    l3.next.next = ListNode(temp_l3[2]);

    return l3

l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

result = Solution().addTwoNumbers(l1, l2)
while result:
  print(result.val)
  result = result.next
# 7 0 8