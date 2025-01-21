

def count_of_atoms(formula: str) -> str:

    i = 0
    stack = [{}]
    
    while i < len(formula):
        if formula[i] == "(":
            i += 1
            stack.append({})
        elif formula[i] == ")":
            i += 1
            atoms = stack.pop()
    
            multiplier = 1
    
            if i < len(formula) and formula[i].isdigit():
                # Parse the multiplier following the closing parenthesis.
                start = i

                while i < len(formula) and formula[i].isdigit():
                    i += 1
                multiplier = int(formula[start:i])
            # Update the counts with the multiplied values.
            for atom, num in atoms.items():
                stack[-1][atom] = stack[-1].get(atom, 0) + num * multiplier
        else:
            # Parse an atom and its count.
            start = i
            # Move to the next character after the uppercase letter.
            i += 1
    
            while i < len(formula) and formula[i].islower():
                i += 1
            atom = formula[start:i]
    
            # Parse the count of the atom (if any).
            num = 0
    
            while i < len(formula) and formula[i].isdigit():
                num = num * 10 + int(formula[i])
                i += 1
            num = max(num, 1)
    
            # Add the atom and its count to the current dictionary.
            if atom in stack[-1]:
                stack[-1][atom] += num
            else:
                stack[-1][atom] = num

    atoms = stack[0]   
    result = []

    for atom in sorted(atoms.keys()):
        num = atoms[atom]
        result.append(atom + (str(num) if num > 1 else ""))

    return "".join(result)
    
if __name__ == "__main__":
    # Test cases.
    test_cases = [
        ("H2O", "H2O"),                     # Simple formula
        ("Mg(OH)2", "H2MgO2"),              # Formula with parentheses
        ("K4(ON(SO3)2)2", "K4N2O14S4"),     # Nested parentheses
        ("C6H12O6", "C6H12O6"),             # Glucose molecule
        ("NaCl", "ClNa"),                   # Simple compound
        ("Ca(Cl2)2", "CaCl4"),              # Parentheses with multiplier
        ("Fe2(SO4)3", "Fe2O12S3"),          # More complex molecule
        ("(CH3)3CCH2OH", "C5H12O"),         # Organic molecule
        ("(H2O)10", "H20O10"),              # Multiple of a group
        ("Al2(SO4)3", "Al2O12S3"),          # Common salt
    ]

    for i, (formula, expected) in enumerate(test_cases):
        result = count_of_atoms(formula)
        print("Case #%d: " % i, end="")
        print(f"Formula: {formula} | Output: {result} | Expected: {expected} | Pass: {result == expected}")


