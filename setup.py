from distutils.core import setup
import py2exe

setup(
    windows=[{"script": "main.py"}],
    options={"py2exe": {"dll_excludes": ["MSVCP90.dll"], "includes": ["ctypes"]}},
    data_files=[('.', ['PrintClickPopUp.dll', 'vcruntime140d.dll', 'ucrtbased.dll'])],
)
