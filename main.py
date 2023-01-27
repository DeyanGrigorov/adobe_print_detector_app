import ctypes
import os
import sys

while True:
    dll_path = os.path.join(os.path.dirname(os.path.abspath(sys.argv[0])), 'PrintClickPopUp.dll')
    dependency_path_one = os.path.join(os.path.dirname(os.path.abspath(sys.argv[0])), 'vcruntime140d.dll')
    dependency_path_two = os.path.join(os.path.dirname(os.path.abspath(sys.argv[0])), 'ucrtbased.dll')
    dll = ctypes.WinDLL(dll_path)
    dependency_one = ctypes.WinDLL(dependency_path_one)
    dependency_two = ctypes.WinDLL(dependency_path_two)
    dll.HookCallback()
