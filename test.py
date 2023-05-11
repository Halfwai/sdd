import unittest

class TestSetForOneModule(unittest.TestCase):

    # All tests need to start with "test"
    def test_a(self):
        self.assertEqual(13, "13")
    def test_b(self):
        self.assertNotEqual(13, 4)
    def test_c(self):
        self.assertTrue(False)
    def test_d(self):
        self.assertFalse(True)
    def test_e(self):
        self.assertIs(13, 13)
    def test_f(self):
        self.assertIsNone(1)
    def test_g(self):
        self.assertIn(2, [1, 4, 5])
    def test_h(self):
        self.assertIsInstance(1, list)

unittest.main(argv=['ignored', '-v'], exit=False)