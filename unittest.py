import unittest

class TestSetForOneModule(unittest.TestCase):

    def test_arithmetic_pass(self):
        self.assertEqual(2 + 2, 4)
    def test_arithmetic_fail(self):
        self.assertEqual(2+2, 3)


unittest.main(argv=['ignored', '-v'], exit=False)