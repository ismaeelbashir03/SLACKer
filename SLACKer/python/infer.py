from mlx_lm import load, generate
import sys
import os

if __name__ == "__main__":
    prompt = sys.argv[1]
    model, tokenizer = load("mlx-community/Llama-3.2-3B-Instruct")

    if hasattr(tokenizer, "apply_chat_template") and tokenizer.chat_template is not None:
        messages = [{"role": "user", "content": prompt}]
        prompt = tokenizer.apply_chat_template(
            messages, tokenize=False, add_generation_prompt=True
        )

    response = generate(model, tokenizer, prompt=prompt, verbose=False)
    
    os.makedirs("SLACKer/tmp", exist_ok=True)
    with open("SLACKer/tmp/response.txt", "w") as f:
        f.write(response)
    