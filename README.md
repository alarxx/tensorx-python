# tensorx-python

Python bindings for the Tensor-library

- C++20
- CMake
- Python3
- pybind11
- scikit-build-core

---

Example:
```python
import tensorx
print(tensorx)

import tensorx._tensorx
print(tensorx._tensorx)

print("add_ints:", tensorx.add_ints(2, 3))

print("make_tensor:")
tensorx.make_tensor()

t0 = tensorx.Tensor()
print("t0.rank:", t0.rank, "t0.dims:", t0.dims, "t0.length:", t0.length)
print("t0:", t0)

s = tensorx.scalar(3.14)
print("s:", s)
print("s.rank:", s.rank, "s.dims:", s.dims, "s.length:", s.length)
print("s.get:", s.get())     # 3.14
s.set(2.71)
print("s.set(2.71)->s.get:", s.get())     # 2.71

t1 = tensorx.Tensor(2, (2, 3))
print("t1.rank:", t1.rank, "t1.dims:", t1.dims, "t1.length:", t1.length)
print("t1:", t1)

t2 = tensorx.Tensor(2, 3, 4)
print("t2.rank:", t2.rank, "t2.dims:", t2.dims, "t2.length:", t2.length)
print("t2:", t2)

v = tensorx.from_list([1, 2, 3])
print("v:", v)

m = tensorx.from_list([
    [1,2,3],
    [4,5,6],
    [7,8,9]
])
print("m:", m)
print("m.rank:", m.rank, "m.dims:", m.dims, "m.length:", m.length)
print("m.get(1, 1):", m.get(1, 1))
```

---

Add Tensor-library:
```sh
git submodule add -b c++mappings git@github.com:alarxx/Tensor-library.git
```

---

Install Docker:
Root:
```sh
apt install docker.io
sudo systemctl enable docker # autostart
sudo systemctl start docker
sudo systemctl status docker
sudo usermod -aG docker $USER
```
User:
```sh
su -c "sudo usermod -aG docker $USER"
newgrp docker
docker version
docker ps
```

---


```sh
apt install python3 python3-full python3-pip python3-venv
#sudo apt install python3.8
python3 --version
python3 -m venv .venv
. .venv/bin/activate
python -m pip install --upgrade pip
python -m pip install --upgrade build
python -m pip install -U twine
python -m pip install -U cibuildwheel
```

---

Build with **hatchling** vs. **scikit_build_core** (CMake).

Generating distribution archives from `pyproject.toml` file with configuration metadata:
```sh
python -m build
```
- `.tar.gz` - source distribution
- `.whl` - built distribution

Try to install locally:
```sh
python -m pip install --force-reinstall dist/*.whl
```
- `--force-reinstall` - if version didn't change

Uninstall local tensorx-python:
```sh
python -m pip uninstall tensorx-python
```

Inside tensorx/ should be shared libraries (.so)
```sh
unzip -l dist/*.whl
```

---

Cross-platform build:
```sh
cibuildwheel --output-dir dist
```

Upload to PyPI:
```sh
python -m twine upload dist/*
```
